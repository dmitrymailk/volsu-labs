#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>
using namespace std;

int main()
{
  // TASK 1 ВАРИАНТ 1
  vector<int> some_list = {1, 2, 3, 0, 4, 12, 3, 4, 1, 2, 3, 4};
  set<int> some_list_part_1(some_list.begin(), some_list.begin() + some_list.size() / 2);
  set<int> some_list_part_2(some_list.begin() + some_list.size() / 2, some_list.end());

  if (includes(some_list_part_1.begin(),
               some_list_part_1.end(),
               some_list_part_2.begin(),
               some_list_part_2.end()))
    cout << "TRUE\n";
  else
    cout << "FALSE\n";
  return 0;
}