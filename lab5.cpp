#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// class Coordinate
// {
// private:
//   int x, y;

// public:
//   Coordinate(int cx = 0, int cy = 0)
//   {
//     x = cx;
//     y = cy;
//   }

//   Coordinate operator+(Coordinate const &obj)
//   {
//     Coordinate res;
//     res.x = x + obj.x;
//     res.y = y + obj.y;
//     return res;
//   }

//   Coordinate operator>(Coordinate const &obj)
//   {
//     cout << "You can't do it \n";
//   }
//   Coordinate operator+(int num)
//   {
//     cout << "You can't do it " << num << "\n";
//   }
//   void print() { cout << "x- " << x << " y- " << y << "\n"; }
// };

// int main2()
// {

//   Coordinate p1(0, 0), p2(1, 1);
//   Coordinate p3 = p1 + p2;
//   p3.print();
//   p1 > p3;
//   p3 + 10;
//   return 0;
// }

class Date
{
public:
  // Date(int d = 0, int m = 0, int y = 0)
  // {
  //   day_now = d;
  //   month_now = m;
  //   year_now = y;
  // }
  time_t now = time(0);
  tm *ltm = localtime(&now);
  //(getYear()%4||( getYear() %100=0&&getYear()%400))?
  int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int day_now;   // = getDay();
  int month_now; // = getMonth();
  int year_now;  // = getYear();

  string currentDate; // = to_string(day_now) + ":" + to_string(month_now) + ":" + to_string(year_now);

  Date()
  {
    day_now = getDay();
    month_now = getMonth();
    year_now = getYear();
    currentDate = to_string(day_now) + ":" + to_string(month_now) + ":" + to_string(year_now);
  }
  Date(int d, int m, int y)
  {
    day_now = d;
    month_now = m;
    year_now = y;
    currentDate = to_string(day_now) + ":" + to_string(month_now) + ":" + to_string(year_now);
  }
  string getFullTime()
  {
    return currentDate;
  }

  void print()
  {
    cout << "\n"
         << currentDate << "\n";
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

  // bool CompareDates( Date date1, Date date2)
  //   {
  //     if (date1 == date2)
  //       return "Dates are equal";
  //     if (date1 > date2)
  //     {
  //       return "Date1 is bigger than Date2";
  //     }
  //     else
  //     {
  //       return "Date2 is bigger than Date1";
  //     }
  //   }

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

  Date operator+(int days)
  {
    Date newDate(day_now, month_now, year_now);
    addDays(day_now, month_now, year_now, days);
    return newDate;
  }
  Date operator++(int)
  {
    Date newDate(day_now, month_now, year_now);
    addDays(day_now, month_now, year_now, 1);
    return newDate;
  }

  bool operator==(Date date)
  {
    if (currentDate == date.currentDate)
      return true;
    return false;
  }
  bool operator>(Date date)
  {
    if (currentDate > date.currentDate)
      return true;
    return false;
  }
  bool operator<(Date date)
  {
    if (currentDate < date.currentDate)
      return true;
    return false;
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

    month_now = m2;
    year_now = y2;
    day_now = d2;
    currentDate = to_string(day_now) + ":" + to_string(month_now) + ":" + to_string(year_now);
    ;
    // this->print();

    // cout << "\n" + to_string(d1) + ":" + to_string(m1) + ":" + to_string(y1) + "\n" + to_string(d2) + ":" + to_string(m2) + ":" + to_string(y2) + "\n";
  }
};

int main()
{
  Date date;
  date.print();
  date++;
  date.print();
  date++;
  date.print();
  date + 10;
  date.print();

  Date date1(1, 2, 3), date2(1, 5, 3);
  if (date1 < date2 && !(date1 == date2) && !(date2 < date1))
  {
    cout << "yes"
         << "\n";
  }
  else
  {
    cout << "no"
         << "\n";
  }
}