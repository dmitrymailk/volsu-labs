#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct subject
{
  string subject_name;
  string teacher_name;
  int lectures_amount;
  int labs_amount;
};

subject *read_csv(string filename, int lines_amount, int cols_amount)
{
  string line, word;
  subject *lines = new subject[lines_amount];
  try
  {
    ifstream myfile(filename);

    string val;
    int line_idx = 0;
    while (getline(myfile, line))
    {

      subject line_vals;
      stringstream s(line);
      int col_idx = 0;
      string *temp_chunks = new string[cols_amount];

      // считываем строчку до запятой и добавляем во временный массив
      while (getline(s, word, ','))
      {
        temp_chunks[col_idx] = word;
        col_idx += 1;
      }
      // добавляем полученную строку в структуру subject
      line_vals = {temp_chunks[0], temp_chunks[1], atoi(temp_chunks[2].c_str()), atoi(temp_chunks[3].c_str())};

      lines[line_idx] = line_vals;
      line_idx += 1;
    }
    myfile.close();
  }
  catch (ifstream::failure e)
  {
    cerr << "Exception opening/reading/closing file\n";
  }

  return lines;
}

void print_csv(subject *csv, int lines_amount, int cols_amount)
{
  const int w = 14;
  for (int i = 0; i < lines_amount; i++)
  {
    cout
        << setw(w)
        << csv[i].subject_name << "|"
        << setw(w)
        << csv[i].teacher_name << "|"
        << setw(w)
        << csv[i].lectures_amount << "|"
        << setw(w)
        << csv[i].labs_amount << "\n";
  }
}

void subject_report(subject *csv, int lines_amount, int cols_amount)
{
  const int lesson_time = 2;
  int full_time = 0;

  for (int i = 0; i < lines_amount; i++)
  {
    int temp_time = (csv[i].lectures_amount + csv[i].labs_amount) * lesson_time;
    full_time += temp_time;

    cout << "Subject name => " << csv[i].subject_name << "\n";
    cout << "Teacher name => " << csv[i].teacher_name << "\n";
    cout << "Subject time duration => " << temp_time << "\n";
    cout << "\n";
  }

  cout << "Full time => " << full_time << "\n";
}

int main()
{
  int lines_amount = 4;
  int cols_amount = 4;

  subject *csv = read_csv("data", lines_amount, cols_amount);

  print_csv(csv, lines_amount, cols_amount);

  subject_report(csv, lines_amount, cols_amount);

  return 0;
}
