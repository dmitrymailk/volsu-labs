#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class programmer
{
private:
  string name;
  string surname;
  int xp;
  bool like_learing;
  int years;
  int pet_projects;
  vector<string> langs = {"Pascal"};
  vector<string> ideas = {};

public:
  int skill;
  int money;
  programmer(string _name = "Stranger", string _surname = "Thing")
  {
    name = _name;
    surname = _surname;
    money = rand() % 4000;
    xp = 100;
    like_learing = true;
    years = 18;
    skill = rand() % 50;
    pet_projects = 0;
  }

  void eat()
  {
    money -= 50;
  }

  string code()
  {
    string pseudo_code = "";
    for (int i = 0; i < skill; i++)
      pseudo_code += " code";
  }
  void sleep()
  {
    ideas.push_back(generate_idea());
  }

  void repeat()
  {
    years += 1;
    skill += 1;
    if (years < 35)
    {
      eat();
      code();
      sleep();
      repeat();
    }
    else
      cout << "Burn out!\n";
  }

  string generate_idea()
  {

    if (rand() % 2)
    {
      skill += 2;
      return "contribute to famous project";
    }
    else
    {
      skill += 10;
      if (skill > 50)
        pet_projects += 1;
      return "write own framework";
    }
  }

  string say()
  {
    return name + " " + surname;
  }
};

class programmers_group
{
private:
  vector<programmer> students;

public:
  int max_students = 50;
  string name;

  group(string _name = "MOS-191")
  {
    name = _name;
  }

  void add_student(programmer student)
  {
    students.push_back(student);
  }

  void add_student(string _name, string _surname)
  {
    students.push_back(programmer(_name, _surname));
  }

  programmer find_same(programmer student)
  {
    programmer temp_student;

    for_each(students.begin(), students.end(), [&student, &temp_student](programmer &coder) {
      if (student.generate_idea() == coder.generate_idea() && student.say() != coder.say())
      {
        temp_student = coder;
      }
    });
    return temp_student;
  }

  void babbling()
  {
    for_each(students.begin(), students.end(), [](programmer &coder) {
      cout << "I'm " + coder.say() << "\n";
    });
    cout << "\n";
  }

  void send_down(programmer student)
  {
    vector<programmer>::iterator pos = find_if(students.begin(), students.end(), [&student](programmer &coder) {
      return coder.say() == student.say();
    });
    students.erase(pos, pos + 1);
  }

  void presence()
  {
    if (!students.empty())
      cout << "we are here!\n";
    else
      cout << "ZzZzZz...\n";
  }

  void reverse_group()
  {
    reverse(students.begin(), students.end());
  }

  void koronavirus()
  {
    students.erase(students.begin(), students.end());
  }

  void sort_by_name()
  {
    sort(students.begin(), students.end(), [](programmer &coder_1, programmer &coder_2) {
      return (coder_1.say() < coder_2.say());
    });
  }

  programmer most_rich()
  {
    vector<programmer>::iterator max = max_element(students.begin(),
                                                   students.end(),
                                                   [](programmer &coder_1, programmer &coder_2) {
                                                     return (coder_1.money < coder_2.money);
                                                   });
    return *max;
  }

  void dance()
  {
    random_shuffle(students.begin(), students.end());
  }

  int count_skillful_students()
  {
    return (int)count_if(students.begin(),
                         students.end(),
                         [](programmer &coder) { return coder.skill > 20; });
  }

  programmer &
  operator[](int i)
  {
    return students[i];
  }
};

int main()
{
  srand(time(NULL));

  programmers_group mos_191;
  mos_191.add_student("Player", "D");
  mos_191.add_student("Player", "C");
  mos_191.add_student("Player", "A");
  mos_191.add_student("Player", "B");
  mos_191.add_student("Player", "G");
  mos_191.add_student("Player", "F");
  mos_191.babbling();

  mos_191.sort_by_name();
  mos_191.babbling();

  mos_191.reverse_group();
  mos_191.babbling();

  cout << mos_191.most_rich().say() << "\n";
  cout << "Amount of skillful students = " << mos_191.count_skillful_students() << "\n";

  mos_191.send_down(mos_191[0]);
  mos_191.babbling();

  mos_191.send_down(mos_191[1]);
  mos_191.babbling();

  programmer freelancer("Artem", "Popov");

  programmer same_student = mos_191.find_same(freelancer);
  cout << same_student.say() + "\n";

  mos_191.koronavirus();
  mos_191.babbling();
  mos_191.babbling();
}