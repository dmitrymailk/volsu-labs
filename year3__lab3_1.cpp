#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstring>
#include <vector>
using namespace std;
// https://lingvo-gap.com/article/bc1f51c1c7216b9620f6f58767086b100d2b8e4bed0c27285fd02d08
class Task
{
public:
  string text = "";

  Task()
  {
    text = read_text("text.txt");
  }

  void task_1()
  {
    vector<string> lines = split(text, "|");

    vector<vector<string>> words_by_line;
    for (string line : lines)
      words_by_line.push_back(split(line));

    for (auto line : words_by_line)
    {
      int count_words = 0;
      for (auto word : line)
        if (is_word(word))
          count_words++;

      cout << "Words amount " << count_words << "\n";
    }
  }

  void task_2()
  {
    cout << replace("Hello i'm a d.i.m.w.e.b", ".", "---") << "\n";
  }

  void task_3()
  {
    int max_len = 0;
    int pos = 0;
    vector<string> lines = split(text, "|");
    for (int i = 0; i < lines.size(); i++)
    {
      if (lines[i].length() > max_len)
      {
        max_len = lines[i].length();
        pos = i;
      }
    }
    cout << "Pos max line is " << pos << "\n";
  }

  void task_4()
  {
    int max_len = 0;
    int pos = 0;
    string max_line;
    vector<string> lines = split(text, "|");
    for (int i = 0; i < lines.size(); i++)
    {
      if (lines[i].length() > max_len)
      {
        max_len = lines[i].length();
        max_line = lines[i];
        pos = i;
      }
    }

    cout << replace(text, max_line, "") << "\n";
  }

  void task_5()
  {
    cout << split(text, ".")[0] << "\n";
  }
  void task_6()
  {
    string str = "Wri123ting ab123out yours123elf in any capa123city can fe123el like an imposs123ible task";
    vector<string> words = split(str, " ");
    for (auto word : words)
      cout << palindrom_word(word) << " ";
  }

  bool is_word(string word)
  {
    char *cword = new char[word.length() + 1];
    strcpy(cword, word.c_str());

    bool is_word = true;
    for (int i = 0; i < word.length(); i++)
    {
      if (isalpha(cword[i]) == 0)
      {
        is_word = false;
        break;
      }
    }

    return is_word;
  }

  string read_text(const string filename)
  {
    string line, temp;
    ifstream myfile(filename);
    if (myfile.is_open())
    {
      while (getline(myfile, temp))
      {
        line += temp;
      }
      myfile.close();
    }
    else
      cout << "Unable to open file";
    return line;
  }

  vector<string> split(string text, string delimiter = " ")
  {
    string ends_of_word = delimiter;
    vector<string> words;
    int start = 0;
    for (int i = 0; i < text.size(); i++)
    {
      for (int j = 0; j < ends_of_word.size(); j++)
      {
        if (text[i] == ends_of_word[j])
        {
          string sub_str = text.substr(start, i - start);
          if (sub_str.size() > 0)
            words.push_back(sub_str);
          start = i + 1;
        }
      }
    }

    return words;
  }

  string replace(string text, string token_to_replace, string replaced_token)
  {
    int pos;
    while ((pos = text.find(token_to_replace)) != -1)
      text.replace(pos, token_to_replace.length(), replaced_token);
    return text;
  }

  string palindrom_word(string word)
  {
    string temp_word = "";
    for (int i = word.length(); i > 0; i--)
      temp_word += word[i - 1];
    return word + temp_word;
  }
};

int main()
{
  Task task;
  // task.task_1();
  // task.task_2();
  // task.task_3();
  // task.task_4();
  // task.task_5();
  task.task_6();

  return 0;
}