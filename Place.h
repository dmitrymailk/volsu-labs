class Place
{
public:
  int count_people = 0;
  int gravitation = 10;
  string planet = "Earth";

  int get_count_people()
  {
    return count_people;
  };

  int get_gravitation()
  {
    return gravitation;
  };

  string get_planet()
  {
    return planet;
  };
  void set_count_people(int some)
  {
    count_people = some;
  };

  void set_gravitation(int some)
  {
    gravitation = some;
  };

  void set_planet(string some)
  {
    planet = some;
  };
  void show_count_people()
  {
    cout << count_people << "\n";
  };

  void show_gravitation()
  {
    cout << gravitation << "\n";
  };

  void show_planet()
  {
    cout << planet << "\n";
  };
  virtual void show()
  {
    cout << "show\n";
  }
  ~Place() {}

  Place(const Place &p)
  {
    count_people = p.count_people;
    gravitation = p.gravitation;
    planet = p.planet;
  }
};
