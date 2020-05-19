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

class Audio
{
public:
  string name = "";
  string type = ".mp3";
  string style = "";
  string author = "";
  int cost = 0;
  int length = 0;
  Audio()
  {
    cout << "Audio\n";
  }
  Audio(string _name = "unknown",
        string _type = ".mp3",
        string _style = "unknown",
        string _author = "unknown",
        int _cost = 0,
        int _length = 0)
  {
    name = _name;
    type = _type;
    style = _style;
    author = _author;
    cost = _cost;
    length = _length;
  }
  Audio(const Audio &a)
  {
    name = a.name;
    type = a.type;
    style = a.style;
    author = a.author;
    cost = a.cost;
    length = a.length;
  }
  ~Audio() {}
};

class Library
{

  typedef vector<Audio> playlist;

public:
  playlist play_list;
  Library()
  {
    cout << "Library was created\n";
  }

  add(Audio audio)
  {
    play_list.push_back(audio);
  }

  Audio getByPos(int pos_track)
  {
    try
    {
      return play_list[pos_track];
    }
    catch (const std::exception &e)
    {
      cout << e.what() << "\n";
    }
  }

  void deepSearch(string _name = "",
                  string _type = ".mp3",
                  string _author = "")
  {
    vector<string> res_by_name;
    vector<string> res_by_type;
    vector<string> res_by_author;

    for (auto item : play_list)
      res_by_name.push_back(item.name);
    for (auto item : play_list)
      res_by_type.push_back(item.type);
    for (auto item : play_list)
      res_by_author.push_back(item.author);

    playlist audio_by_name = this->str_like(res_by_name, _name);
    playlist audio_by_type = this->str_like(res_by_type, _type);
    playlist audio_by_author = this->str_like(res_by_author, _author);

    bold("Search by name:", _name);
    for (Audio item : audio_by_name)
    {
      this->print_audio(item);
    }
    bold("Search by type:", _type);
    for (Audio item : audio_by_type)
    {
      this->print_audio(item);
    }
    bold("Search by author:", _author);
    for (Audio item : audio_by_author)
    {
      this->print_audio(item);
    }
  }

  playlist str_like(vector<string> source_arr, string keyword)
  {
    if (keyword.size())
    {
      playlist temp_arr;
      for (int i = 0; i < source_arr.size(); i++)
      {
        if (Library::lower(source_arr[i]).find(Library::lower(keyword)) != string::npos)
        {
          temp_arr.push_back(play_list[i]);
          // cout << source_arr[i] << "\n";
        }
      }
      return temp_arr;
    }
    else
    {
      return play_list;
    }
  }

  remove(int pos_track)
  {
    play_list.erase(play_list.begin() + pos_track);
  }

  void show_all()
  {
    bold("All elements", "", "43");
    for (Audio item : play_list)
    {
      this->print_audio(item);
    }

    cout << color_text("-------------------------------------------------------\n", "31");
  }

  void edit_by_pos(int pos)
  {
    this->print_audio(this->getByPos(pos));
    cout << "Please type name\n";
    string _name;
    cin >> _name;
    play_list[pos].name = _name;
    cout << "Please type author\n";
    string _author;
    cin >> _author;
    play_list[pos].author = _author;
    cout << "Please type style\n";
    string _style;
    cin >> _style;
    play_list[pos].style = _style;

    // this->print_audio(this->getByPos(pos));
  };

  void print_audio(Audio audio)
  {
    int distance = 15;
    cout << color_text("Name: ", "33") << setw(distance) << audio.name << " "
         << color_text("File type: ", "33") << setw(distance) << audio.type << "\n"
         << color_text("Style:", "33") << setw(distance) << audio.style << " "
         << color_text("Author: ", "33") << setw(distance) << audio.author << "\n"
         << color_text("Cost: ", "33") << setw(distance) << audio.cost << " "
         << color_text("File duration: ", "33") << setw(distance) << audio.length << "\n"
         << color_text("----", "32")
         << "\n";
  }

  static string lower(string str)
  {
    for (int i = 0; i < str.length(); i++)
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;
    return str;
  }
};

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