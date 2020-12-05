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
    // пока программист спит он генерирует идеи
    ideas.push_back(generate_idea());
  }

  void repeat()
  {
    // функция вызывается рекурсивно до тех пор пока возраст меньше 35
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
    // генерация идеи
    //  если рандомно сгенерированное число 1 тогда мы увеличиваем skill на 2 и тд
    // если 0 то увеличиваем skill на 10 и тд
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

// класс объединяющий класс programmer
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

  // добавдение нового студента в конец группы
  // если на вход поступает объект класса programmer
  void add_student(programmer student)
  {
    students.push_back(student);
  }

  // создание добавление нового студента в конец группы
  // если на вход поступает токько его имя и фамилия
  void add_student(string _name, string _surname)
  {
    students.push_back(programmer(_name, _surname));
  }

  // функция которого ищет похожего студента
  // у которого результат значения функции generate_idea() совпадают
  // соответсвенно результат должен быть всегда разный
  programmer find_same(programmer student)
  {
    programmer temp_student;

    // перебор массива при помощи for_each
    // пример https://www.geeksforgeeks.org/for_each-loop-c/
    for_each(students.begin(), students.end(),
             // используется lambda expression
             // пример https://www.geeksforgeeks.org/lambda-expression-in-c/
             [&student, &temp_student](programmer &coder) {
               if (student.generate_idea() == coder.generate_idea() && student.say() != coder.say())
               {
                 temp_student = coder;
               }
             });
    return temp_student;
  }

  // функция болтать, мы перебераем каждого студента и вызываем у него функцию say()
  void babbling()
  {
    for_each(students.begin(), students.end(), [](programmer &coder) {
      cout << "I'm " + coder.say() << "\n";
    });
    cout << "\n";
  }

  // функция отчисления студента
  // на вход поступает сам студент и дальше ищется позиция в списке и удаляется
  void send_down(programmer student)
  {
    function_type("send_down");
    vector<programmer>::iterator pos = find_if(students.begin(), students.end(), [&student](programmer &coder) {
      return coder.say() == student.say();
    });
    students.erase(pos, pos + 1);
  }

  // функция присутствия группы
  // если в ней никого нет, тогда ZzZzZz
  // иначе we are here
  void presence()
  {
    if (!students.empty())
      cout << "we are here!\n";
    else
      cout << "ZzZzZz...\n";
  }

  // разворачивает массив группы наборот
  void reverse_group()
  {
    function_type("reverse_group");
    reverse(students.begin(), students.end());
  }

  // полностью удаляет студентов из списков группы (навсегда)
  void koronavirus()
  {
    function_type("korona");
    students.erase(students.begin(), students.end());
  }

  // сортирует по имени список группы
  void sort_by_name()
  {
    function_type("sort by name");
    sort(students.begin(), students.end(), [](programmer &coder_1, programmer &coder_2) {
      return (coder_1.say() < coder_2.say());
    });
  }

  // находит в группе самого богатого по признаку money
  programmer most_rich()
  {
    function_type("most rich");
    vector<programmer>::iterator max = max_element(students.begin(),
                                                   students.end(),
                                                   [](programmer &coder_1, programmer &coder_2) {
                                                     return (coder_1.money < coder_2.money);
                                                   });
    return *max;
  }
  //  функция dance рандомно перемешивает список группы
  void dance()
  {
    function_type("dance");
    random_shuffle(students.begin(), students.end());
  }

  // считает количество студентов чей скилл больше 20
  int count_skillful_students()
  {
    return (int)count_if(students.begin(),
                         students.end(),
                         [](programmer &coder) { return coder.skill > 20; });
  }

  void function_type(string to_do)
  {
    cout << to_do << "\n";
  }

  // чисто оператор для удобства
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
  mos_191.presence();
  mos_191.add_student("Player", "D");
  mos_191.add_student("Player", "C");
  mos_191.add_student("Player", "A");
  mos_191.add_student("Player", "B");
  mos_191.add_student("Player", "F");
  mos_191.presence();
  mos_191.babbling();

  mos_191.sort_by_name();
  mos_191.babbling();

  mos_191.reverse_group();
  mos_191.babbling();

  mos_191.dance();
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