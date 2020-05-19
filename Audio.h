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