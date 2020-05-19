// Описать класс «Каталог аудиозаписей» с полем - массив объектов класса «Аудиозапись».
// Предусмотреть возможность работы с произвольным числом аудиозаписей, поиска
// аудиозаписи по каким-либо признакам, добавления, редактирования и удаления
// аудиозаписи.

#include <string>
#include <iostream>
#include <vector>
#include <cwctype>
#include <iomanip>
using namespace std;

string color_text(string content, string color)
{
  string start = "\x1B[";
  string end = "\033[0m";
  string new_str = start + color + "m" + content + end;
  return new_str;
};

void bold(string content, string bit = "", string color = "44")
{
  string start = "\033[3;";
  string end = "\033[0m";
  content += bit;
  string new_str = start + color + ";30m" + content + end;
  cout << new_str << "\n";
};

#include "Audio.h"
#include "Library.h"

int main()
{
  Library libr;

  Audio track_1("nobody listening", "mp3", "alternative", "linkin park", 200, 257);
  Audio track_2("breaking the habbit", "wav", "rock", "link dark");
  Audio track_3("abc xyz", "mp3", "rock", "bob marty", 100);

  libr.add(track_1);
  libr.add(track_2);
  libr.add(track_3);

  libr.show_all();
  libr.deepSearch("ing", "m", "bo");
  libr.remove(1);
  libr.show_all();
  libr.edit_by_pos(1);
  libr.show_all();
  return 0;
}