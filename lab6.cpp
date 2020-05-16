// Классы – место (площадь, название, ...), область (количество населенных пунктов,
// руководство, ...), город (область, количество жителей, мэр, ...), деревня (район, ...)
#include <string>
#include <iostream>
using namespace std;
#include "Place.h"
#include "Area.h"
#include "Town.h"
#include "Village.h"

int main()
{
  Place *base_place[2];

  base_place[0] = new Area();
  base_place[1] = new Town();
  base_place[2] = new Village();

  for (int i = 0; i < 3; i++)
  {
    base_place[i]->show();
  }
  return 0;
}
