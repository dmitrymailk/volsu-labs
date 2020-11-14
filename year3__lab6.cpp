#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
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

  // TASK 2 ВАРИАНТ 1

  vector<int> task_2 = {2, 2, 2, 2, 3, 3, 3, 4, 4, 66, 66, -3, 2, 1, 1, 1, 1, 1};
  set<int> task_2_unique(task_2.begin(), task_2.end());
  map<int, int> task_2_statistics;
  for (auto num : task_2_unique)
  {
    int amount = count(task_2.begin(), task_2.end(), num);
    task_2_statistics.insert(pair<int, int>(num, amount));
  }

  for_each(task_2_statistics.begin(), task_2_statistics.end(), [](pair<int, int> item_1) {
    cout << item_1.first << " => " << item_1.second << "\n";
  });

  return 0;
}