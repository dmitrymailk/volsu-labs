#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
using namespace std;

class lab_6 {
 public:
  vector<int> main_vec = {5, 1, 1, 2, 2, 2, 3, 3, 3, 3};
  vector<string> words = {"SAY",      "IT",    "EXPLAIN", "YOURSELF", "GO",
                          "ON",       "JUST",  "HANG",    "YOURSELF", "NO",
                          "ONE",      "TAKES", "PRIDE",   "FOR",      "PAIN",
                          "SAVE",     "YOUR",  "GAME",    "NO",       "ONE",
                          "BELIEVES", "YOU",   "ANYWAY"};

  lab_6() {
    cout << "\n";
    // this->task_1();
    this->task_2();
  }

  void task_1() {
    set<int> uniq_vec(this->main_vec.begin(), this->main_vec.end());

    if (uniq_vec.size() > 2) {
      set<int>::reverse_iterator rev;
      // prints all elements in reverse order
      for (rev = next(uniq_vec.rbegin(), 1); rev != prev(uniq_vec.rend(), 1);
           rev++)
        cout << *rev << " ";
    }
  }

  void task_2() {
    map<char, vector<string>> same_endings;
    set<char> all_ends;

    // get all unique letters
    for (auto item : words) {
      char last_char = *(prev(item.end(), 1));
      all_ends.insert(last_char);
    }

    // create pair letter => list of words
    for (char item : all_ends) {
      vector<string> temp_vec;
      copy_if(words.begin(), words.end(), back_inserter(temp_vec),
              [&item](string word) { return *prev(word.end(), 1) == item; });

      same_endings.insert(pair<char, vector<string>>(item, temp_vec));
    }

    // print results
    for_each(same_endings.begin(), same_endings.end(),
             [](pair<char, vector<string>> item_1) {
               cout << item_1.first << " => ";

              //  for (auto word : item_1.second) cout << word << " ";
              //  cout << "\n";

              vector<string>::reverse_iterator rev;
              // prints all elements in reverse order
              for (rev = item_1.second.rbegin(); rev != item_1.second.rend();
                  rev++)
                cout << *rev << " ";
              cout << "\n";
             });
  }
};

int main() { 
  lab_6 _; 
}
