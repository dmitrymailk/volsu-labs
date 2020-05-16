class Area : public Place
{
public:
  int some_area1 = 0;
  int some_area2 = 0;

  void boom_some_area1()
  {
    cout << some_area1 << "\n";
  }
  void boom_some_area2()
  {
    cout << some_area2 << "\n";
  }
  Area()
  {
    cout << "Create Area"
         << "\n";
  }
  ~Area()
  {
    cout << "Bye Area"
         << "\n";
  }
};