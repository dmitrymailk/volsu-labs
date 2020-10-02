// Задание 1
// Согласно варианту из Лаб/р 1 реализовать наполнение класса однонаправленного списка или стека,
// реализовать итератор:
#include "lab_files/linked_list.cpp"

int main()
{
  linked_list a;
  a.add_node("qwe qwe");
  a.add_node("qwe");
  a.add_node("qwe 3");
  a.add_node("qwe 4");

  a.show_all();
  a += "DFDFDF";
  a.show_all();

  linked_list a_2;
  a_2.add_node("asd");
  a_2.add_node("asd 2");
  a_2.add_node("asd 3");
  a_2.show_all();

  a += a_2;

  a.show_all();

  // a.replace_all_words("qwe", "aaaaaaaaaaa");
  // // a.show_all();
  // a.pop();
  // // a.show_all();
  // // cout << "\nB\n";
  // linked_list b = a;
  // b.show_all();
  // linked_list c(a);
  // c.show_all();
  // a.show_all();
  cout << (*a).data << "\n";

  return 0;
}