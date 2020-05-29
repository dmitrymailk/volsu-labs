#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

char *substr(const char *src, int m, int n)
{
  int len = n - m;
  char *dest = (char *)malloc(sizeof(char) * (len + 1));
  for (int i = m; i < n && (*(src + i) != '\0'); i++)
  {
    *dest = *(src + i);
    dest++;
  }
  *dest = '\0';
  return dest - len;
}

void sent_tokinazer(char **sents, char *text)
{
  const char *ends = ".!?";

  int i = 0;
  int pos_sent = 0;
  int num_len = 0;
  int start = 0;

  while (text[i] != '\0')
  {
    if (text[i] == ends[0] || text[i] == ends[1] || text[i] == ends[2])
    {
      char *dest = substr(text, start, i);
      start = i + 2;
      sents[pos_sent] = dest;
      pos_sent += 1;
    }
    i++;
  }
}

int sent_tokinazer_len(char *text)
{
  const char *ends = ".!?";
  int count = 0;
  int i = 0;
  while (text[i] != '\0')
  {
    if (text[i] == ends[0] || text[i] == ends[1] || text[i] == ends[2])
      count++;
    i += 1;
  }
  return count;
};

int length_words(char *sent)
{
  int count_spaces = 1;

  for (int i = 0; i < strlen(sent); i++)
    if (sent[i] == ' ')
      count_spaces++;
  return count_spaces;
}

void sents_segregation(char **sents, int counts, int count_sents)
{
  for (int i = 0; i < count_sents; i++)
  {
    if (length_words(sents[i]) == counts)
      cout << sents[i] << "\n";
  }
};

void text_from_file(char *_text, const char *filename)
{
  int c;
  FILE *file;
  file = fopen(filename, "r");
  int pos = 0;
  if (file)
  {
    while ((c = getc(file)) != EOF)
    {
      _text[pos] = c;
      pos += 1;
    }
    fclose(file);
  }
}

void MainTask()
{
  int max_characters = 10000;
  char text[max_characters];
  const char filename[] = "some_text.txt";

  // get text from txt file
  text_from_file(text, filename);

  int sents_len = sent_tokinazer_len(text);
  char **sents = (char **)malloc(sizeof(char *) * sents_len * max_characters);

  // get sentences from text
  sent_tokinazer(sents, text);

  // print sentences which contain 3 words
  int condition_of_words = 3;
  sents_segregation(sents, condition_of_words, sents_len);

  // free memory
  for (int i = 0; i < sents_len; i++)
    delete &sents[i];
}

int main()
{
  MainTask();
  return 0;
}
