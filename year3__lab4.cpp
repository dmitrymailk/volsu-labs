#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//

class m_vector
{
  vector<int> container;
  int index_of_first_part;
  int len;
  int k;

public:
  m_vector(const int _len, const int _k)
  {
    len = _len;
    k = _k;

    container = {23, 3, 2, 1, 4, 5, 6, 70, 8, 9};
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
  }

  void task_1()
  {
    num_task(1);
    // for (int i = 0; i < len; i++)
    //   container.push_back(rand() % 10);
    // for (auto item : container)
    //   cout << item << " ";
    int summ = 0;
    int count = 0;

    for (auto num : container)
    {
      if (num % k == 0)
      {
        summ += num;
        count++;
      }
    }
    if (count > 0)
      cout << "Average sum = " << (float)(summ / count) << "\n";
    else
      cout << "Elements not found\n";
  }

  void task_2()
  {
    num_task(2);
    vector<int>::iterator min = min_element(container.begin(), container.end());
    vector<int>::iterator max = max_element(container.begin(), container.end());

    int start = distance(container.begin(), min);
    int end = distance(container.begin(), max);

    print_vec();
    if (start < end)
    {
      for (int i = start; i <= end; i++)
        container[i] *= -1;
      cout << "\n";
    }
    else
    {
      for (int i = end; i <= start; i++)
        container[i] *= -1;
      cout << "\n";
    }

    print_vec();
  }

  void task_3()
  {
    num_task(3);
    int index_of_neg = -1;
    for (int i = 0; i < container.size(); i++)
      if (container[i] < 0 && i % 2 == 0)
      {
        index_of_neg = i;
        break;
      }

    if (index_of_neg != -1)
    {
      cout << "Index = " << index_of_neg << " Number = " << container[index_of_neg] << "\n";

      vector<int> part_1(container.begin(), container.begin() + index_of_neg);
      vector<int> part_2(container.begin() + index_of_neg, container.begin() + index_of_neg + 1);
      vector<int> part_3(container.begin() + index_of_neg + 1, container.end());
      index_of_first_part = part_3.size() - 1;
      // print_vec(part_1);
      // print_vec(part_2);
      // print_vec(part_3);

      container.clear();
      container.insert(container.end(), part_3.begin(), part_3.end());
      container.insert(container.end(), part_2.begin(), part_2.end());
      container.insert(container.end(), part_1.begin(), part_1.end());

      print_vec();
    }
    else
      cout << "No condition\n";
  }

  void task_4()
  {

    num_task(4);
    vector<int> test = {1, 2, 3, 0, 4, 5, 0, 10, 0, 0};
    print_vec(test);
    test.erase(remove(test.begin(), test.end(), 0), end(test));
    print_vec(test);
  }

  void task_5()
  {
    num_task(5);
    print_vec(container);
    sort(container.begin(), container.begin() + index_of_first_part);
    print_vec(container);
  }

  bool is_zero(int num)
  {
    return num == 0;
  }

  void print_vec()
  {
    for (auto item : container)
      cout << item << " ";
    cout << "\n";
  }

  void num_task(int pos)
  {
    cout << "Task #" << pos << "-----------\n";
  }

  void print_vec(vector<int> some_vector)
  {
    for (auto item : some_vector)
      cout << item << " ";
    cout << "\n";
  }
};

int main()
{
  srand(0);
  m_vector m_vec(10, 2);
  return 0;
}