class Library
{

  typedef vector<Audio> playlist;

public:
  playlist play_list;
  Library()
  {
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
    cout << "Please type name ";
    string _name;
    cin >> _name;
    // cout << "\n";
    play_list[pos].name = _name;
    cout << "Please type author ";
    string _author;
    cin >> _author;
    // cout << "\n";
    play_list[pos].author = _author;
    cout << "Please type style ";
    string _style;
    cin >> _style;
    // cout << "\n";
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