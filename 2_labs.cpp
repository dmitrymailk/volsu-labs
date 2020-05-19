#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> sent_tokinazer(string text)
{
  string ends_of_sent = ".!?";
  vector<string> sents;
  int start = 0;
  for (int i = 0; i < text.size(); i++)
  {
    for (int j = 0; j < ends_of_sent.size(); j++)
    {
      if (text[i] == ends_of_sent[j])
      {
        if (start > 0)
          start++;

        string sub_str = text.substr(start, i - start + 1);
        sents.push_back(sub_str);
        start = i + 1;
      }
    }
  }

  return sents;
};

int length_words(string sent)
{
  int count_spaces = 1;

  for (int i = 0; i < sent.size(); i++)
    if (sent[i] == ' ')
      count_spaces++;
  // cout << count_spaces << "\n";
  return count_spaces;
}

void sents_segregation(vector<string> sents, int counts)
{
  // vector<string> segregated_sents;
  for (int i = 0; i < sents.size(); i++)
  {
    if (length_words(sents[i]) == counts)
      cout << sents[i] << "\n";
  }
};

string text_from_file(string filename)
{
  string text = "";

  ifstream baseFile(filename);
  if (!baseFile)
  {
    cerr << "Unable to open file " << filename;
    exit(1);
  }
  string line;
  while (getline(baseFile, line))
    text += line;

  return text;
}

void MainTask(string filename = "some_text.txt")
{
  string text = text_from_file(filename);
  vector<string> sents = sent_tokinazer(text);
  int condition_of_words = 3;
  sents_segregation(sents, condition_of_words);
}

int main()
{
  MainTask();
  return 0;
}
