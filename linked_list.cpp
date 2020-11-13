#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

class linked_list
{
  // private:
public:
  vector<string> m_list;
  linked_list()
  {
  }
  linked_list(string str)
  {
    m_list.push_back(str);
  }
  ~linked_list()
  {
    delete &m_list;
  }
  linked_list(const linked_list &old_list)
  {
    m_list.assign(old_list.m_list.begin(), old_list.m_list.end());
  }

  linked_list operator=(const linked_list &old_list)
  {
    m_list.assign(old_list.m_list.begin(), old_list.m_list.end());
    return *this;
  }

  void add_node(string str)
  {
    m_list.push_back(str);
  }

  void show_all()
  {
    cout << "\n";
    for (auto item : m_list)
      cout << item << "\n";
    cout << "---------------";
  }

  string replace(string str, string sub_str, string replace_str)
  {
    while (str.find(sub_str) != -1)
    {
      str.replace(str.find(sub_str), sub_str.length(), replace_str);
    }
    return str;
  }

  void replace_all_words(string sub_str, string replace_str)
  {
    for (int i = 0; i < m_list.size(); i++)
    {
      string temp_str = m_list[i];
      if (temp_str.find(sub_str) != -1)
      {
        m_list[i] = this->replace(temp_str, sub_str, replace_str);
      }
    }
  }
  void pop()
  {
    m_list.pop_back();
  }
};