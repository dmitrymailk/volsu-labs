#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

template <class Type>
class m_vector
{
  vector<Type> container;
  int len;
  int k;

public:
  m_vector(const int _len, const int _k)
  {
    len = _len;
    k = _k;

    container = {3, 1, 2, 4, 5, 6, 70, 8, 9, 10};
    task_1();
    task_2();
  }

  void task_1()
  {
    // for (int i = 0; i < len; i++)
    //   container.push_back(rand() % 10);
    // for (auto item : container)
    //   cout << item << " ";
    Type summ = 0;
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
    auto min = min_element(container.begin(), container.end());
    auto max = max_element(container.begin(), container.end());

    int start = index(min);
    int end = index(max);

    print_vec();

    for (int i = start; i <= end; i++)
      container[i] *= -1;
    cout << "\n";

    print_vec();
  }
  int index(auto num)
  {
    return distance(container.begin(), num);
  }

  void print_vec()
  {
    for (auto item : container)
      cout << item << " ";
  }
};

int main()
{
  srand(0);
  m_vector<int> m_vec(10, 2);
  return 0;
}