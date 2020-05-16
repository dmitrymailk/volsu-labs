class Village : public Place
{
public:
  int some_village1 = 0;
  int some_village2 = 0;

  void boom_some_village1()
  {
    cout << some_village1 << "\n";
  }
  void boom_some_village2()
  {
    cout << some_village2 << "\n";
  }
  Village()
  {
    cout << "Create Village"
         << "\n";
  }
  ~Village()
  {
    cout << "Bye Village"
         << "\n";
  }
};
