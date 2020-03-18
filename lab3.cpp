#include <iostream>
#include <vector>
#include <cstdarg>
#include <cmath>
using namespace std;

void DumbPrint()
{
  for (int i = 0; i < 45; i++)
    std::cout << "*"
              << " ";
  std::cout << "\n";
}

void DumbPrint(std::string character, int count)
{
  for (int i = 0; i < count; i++)
    std::cout << character
              << " ";
  std::cout << "\n";
}

void DumbPrint(std::string character)
{
  for (int i = 0; i < 45; i++)
    std::cout << character
              << " ";
  std::cout << "\n";
}

void DumbPrintFix(std::string character = "*", int count = 15)
{
  for (int i = 0; i < count; i++)
    std::cout << character
              << " ";
  std::cout << "\n";
}

void SearchMinN(vector<int> arr)
{
  int min_count = 0;
  int min_el = arr[0];
  int length = arr.size();
  for (int i = 0; i < length; i++)
  {
    if (arr[i] < min_el)
    {
      min_count = i;
      min_el = arr[i];
    }
  }
  std::cout << "Position of min: " << min_count << "\n";
}
void SearchMinN(vector<float> arr)
{
  int min_count = 0;
  float min_el = arr[0];
  int length = arr.size();
  for (int i = 0; i < length; i++)
  {
    if (arr[i] < min_el)
    {
      min_count = i;
      min_el = arr[i];
    }
  }
  std::cout << "Position of min: " << min_count << "\n";
}
void SearchMinN(vector<double> arr)
{
  int min_count = 0;
  double min_el = arr[0];
  int length = arr.size();
  for (int i = 0; i < length; i++)
  {
    if (arr[i] < min_el)
    {
      min_count = i;
      min_el = arr[i];
    }
  }
  std::cout << "Position of min: " << min_count << "\n";
}

template <typename T>
void SearchMinNFix(vector<T> arr)
{
  int min_count = 0;
  double min_el = arr[0];
  int length = arr.size();
  for (int i = 0; i < length; i++)
  {
    if (arr[i] < min_el)
    {
      min_count = i;
      min_el = arr[i];
    }
  }
  std::cout << "Position of min: " << min_count << "\n";
}

void SumInfinityParams(int count, ...)
{
  double sum = 0;
  double sum_sq = 0;
  int N = 0;
  std::va_list args;
  va_start(args, count);
  for (int i = 0; i < count; ++i)
  {
    if (i % 2 == 1)
    {
      double num = va_arg(args, double);
      sum += num;
      N++;
      cout << "Pos: " << i << " Num: " << num << "\n";
    }
    else
    {
      va_arg(args, double);
    }
  }
  va_end(args);
  cout << sum << "\n";
  cout << "Average sum: " << sum / N << "\n";
}

double F(double x)
{
  return x - 1 / (3 + sin(3.6 * x));
}

double SolveEquation(double (*f)(double), double x0, int n)
{
  double x = x0, df, h = 0.00001;
  df = (f(x + h) - f(x)) / h;
  for (int i = 1; i <= n; i++)
    x = x - f(x) / df;
  return x;
}

void Task1()
{
  DumbPrint();
  DumbPrint("qwe");
  DumbPrint("MY", 5);
}

void Task2()
{
  DumbPrintFix();
  DumbPrintFix("asd");
  DumbPrintFix("zxc", 4);
}

void Task3()
{
  // vector<int> arr_i = {1, 2, 3, 4};
  vector<float> arr_f = {1, 2, 0, 4};
  vector<double> arr_d = {1, 2, 3, 4};
  // SearchMinN(arr_i);
  SearchMinN(arr_f);
  SearchMinN(arr_d);
}

void Task4()
{
  vector<float> arr_f = {1, 2, 0, 4};
  vector<double> arr_d = {1, 2, 0, 4, 23, -32};
  // SearchMinN(arr_i);
  SearchMinNFix(arr_f);
  SearchMinNFix(arr_d);
}

void Task5()
{
  SumInfinityParams(8, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.1);
  SumInfinityParams(5, 1.0, 2.0, 3.0, 4.0, 5.0);
}

void Task6()
{
  const int N = 20;
  double x0, x;
  cout << "initial x0 = ";
  cin >> x0;
  //Поиск решения:
  x = SolveEquation(F, x0, N);
  cout << "x = " << x << endl;
}

int main()
{
  // Task1();
  // Task2();
  // Task3();
  // Task4();
  // Task5();
  Task6();
  return 0;
}