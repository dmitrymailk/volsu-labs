class Town : public Place
{
public:
  int some_town1 = 0;
  int some_town2 = 0;

  void boom_some_town1()
  {
    cout << some_town1 << "\n";
  }
  void boom_some_town2()
  {
    cout << some_town2 << "\n";
  }
  Town()
  {
    cout << "Create Town"
         << "\n";
  }
  ~Town()
  {
    cout << "Bye Town"
         << "\n";
  }
};
