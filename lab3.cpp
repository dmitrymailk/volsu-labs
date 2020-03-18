#include <iostream>

void DumbPrint()
{
 for (int i = 0; i < 45; i++)
  std::cout << "*"
            << "\n";
}

void DumbPrint(std::string character, int count)
{
 for (int i = 0; i < count; i++)
  std::cout << character
            << "\n";
}

void DumbPrint(std::string character)
{
 for (int i = 0; i < 45; i++)
  std::cout << character
            << "\n";
}

void DumbPrintFix(std::string character = "*", int count = 45)
{
 for (int i = 0; i < count; i++)
  std::cout << character
            << "\n";
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

int main()
{
 // Task1();
 Task2();
 return 0;
}