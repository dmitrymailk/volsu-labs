#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Date
{
public:
  string currentDate = "";
  time_t now = time(0);
  tm *ltm = localtime(&now);
  //(getYear()%4||( getYear() %100=0&&getYear()%400))?
  int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  string getFullTime()
  {
    currentDate = ctime(&now);
    return ctime(&now);
  }

  int getYear()
  {
    return 1900 + ltm->tm_year;
  }

  int getMonth()
  {
    return 1 + ltm->tm_mon;
  }

  int getDay()
  {
    return ltm->tm_mday;
  }

  template <typename T>
  string CompareDates(T date1, T date2)
  {
    if (date1 == date2)
      return "Dates are equal";
    if (date1 > date2)
    {
      return "Date1 is bigger than Date2";
    }
    else
    {
      return "Date2 is bigger than Date1";
    }
  }

  int getNextDay()
  {
    if (isLeap(getYear()))
      year[1] = 29;
    int currentDay = getDay();
    int maxDays = year[getMonth() - 1];
    if (currentDay + 1 > maxDays)
    {
      return 1;
    }
    else
    {
      return currentDay + 1;
    }
  }

  bool isLeap(int y)
  {
    if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
      return true;

    return false;
  }

  int offsetDays(int d, int m, int y)
  {
    int offset = d;

    switch (m - 1)
    {
    case 11:
      offset += 30;
    case 10:
      offset += 31;
    case 9:
      offset += 30;
    case 8:
      offset += 31;
    case 7:
      offset += 31;
    case 6:
      offset += 30;
    case 5:
      offset += 31;
    case 4:
      offset += 30;
    case 3:
      offset += 31;
    case 2:
      offset += 28;
    case 1:
      offset += 31;
    }

    if (isLeap(y) && m > 2)
      offset += 1;

    return offset;
  }

  void revoffsetDays(int offset, int y, int *d, int *m)
  {
    int month[13] = {0, 31, 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31};

    if (isLeap(y))
      month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
      if (offset <= month[i])
        break;
      offset = offset - month[i];
    }

    *d = offset;
    *m = i;
  }

  string addDays(int d1, int m1, int y1, int x)
  {
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1) ? (366 - offset1) : (365 - offset1);

    int y2, offset2;
    if (x <= remDays)
    {
      y2 = y1;
      offset2 = offset1 + x;
    }

    else
    {
      x -= remDays;
      y2 = y1 + 1;
      int y2days = isLeap(y2) ? 366 : 365;
      while (x >= y2days)
      {
        x -= y2days;
        y2++;
        y2days = isLeap(y2) ? 366 : 365;
      }
      offset2 = x;
    }

    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);

    return "\n" + to_string(d1) + ":" + to_string(m1) + ":" + to_string(y1) + "\n" + to_string(d2) + ":" + to_string(m2) + ":" + to_string(y2) + "\n";
  }
};

int main()
{
  Date date;

  cout << "getFullTime is: " << date.getFullTime() << "\n";
  cout << "getYear is: " << date.getYear() << "\n";
  cout << "getDay is: " << date.getDay() << "\n";
  cout << "getMonth is: " << date.getMonth() << "\n";
  cout << "getNextDay is: " << date.getNextDay() << "\n";
  cout << "isLeap is: " << date.isLeap(date.getYear()) << "\n";
  cout << "CompareDates is: " << date.CompareDates(date.getDay(), date.getNextDay()) << "\n";

  int d = 14, m = 3, y = 2025;
  int x = 366;
  cout << "addDays is: " << date.addDays(d, m, y, x) << "\n";
}