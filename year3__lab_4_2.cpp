// Динамические структуры данных. Шаблоны классов
// Задание 1
// Реализовать класс, включая конструктор по умолчанию, конструктор копии,
// операцию присваивания и другие перегруженные операции.
// Варианты заданий
// При решении задач необходимо описать класс, который используется для представления
// элементов динамической структуры данных.
// Работа с используемой динамической структурой данных при тестировании класса
// может быть построена путем ввода данных: a) с клавиатуры; б) из файла.
// Возможны два варианта решения:
// а) динамическая структура данных постоянно хранится в памяти;
// б) динамическая структура данных хранится в файле.

#include "linked_list.cpp"
#include <fstream>

int main()
{
  linked_list a;

  try
  {
    ifstream myfile("a.txt");
    bool file_is_open = myfile.is_open();
    string line;
    while (getline(myfile, line))
    {
      a.add_node(line);
    }
    myfile.close();
  }
  catch (ifstream::failure e)
  {
    cerr << "Exception opening/reading/closing file\n";
  }

  a.show_all();
  a.replace_all_words("qwe", "aaaaa");
  a.show_all();
  a.pop();
  a.show_all();

  cout << "\nB\n";
  linked_list b = a;
  b.show_all();

  cout << "\nC\n";
  linked_list c(a);
  c.show_all();

  a.pop();
  a.show_all();

  return 0;
}