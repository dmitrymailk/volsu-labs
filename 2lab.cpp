#include <regex>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
using std::cin;
using std::cout;
using std::setw;

int PrintMatches(std::regex reg, std::string filePath)
{
  ifstream baseFile(filePath);
  if (!baseFile)
  {
    cerr << "Unable to open file datafile.txt";
    exit(1);
  }
  ofstream myfile("example.txt");
  string line;
  while (std::getline(baseFile, line))
  {

    std::cout << line << std::endl;
    std::sregex_iterator currentMatch(line.begin(), line.end(), reg);
    std::sregex_iterator lastMatch;

    while (currentMatch != lastMatch)
    {
      std::smatch match = *currentMatch;
      std::cout << match.str() << " FIND MATCH "
                << "\n";
      myfile << match.str() << "\n";
      currentMatch++;
    }
    std::cout << std::endl;
  }
  baseFile.close();
  myfile.close();
}

void printArray(int **array, int height, int width)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      cout << setw(3) << array[i][j];
    }
    cout << "\n";
  }

  cout << "\n";
};

void PrintArrays()
{
  int height, width;
  cout << "Enter array width and height\n";
  cin >> width;
  cin >> height;
  cout << "w= " << width << "\n";
  cout << "h= " << height << "\n";

  int **array = new int *[height];
  for (int i = 0; i < height; i++)
    array[i] = new int[width];

  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      array[i][j] = rand() % 100 + 1;

  //print
  printArray(array, height, width);

  //creating new array with zeros
  int newW = width + width / 2;
  int **newA = new int *[height];

  for (int i = 0; i < height; i++)
    newA[i] = new int[newW];

  for (int i = 0; i < height; i++)
    for (int j = 0; j < newW; j++)
      newA[i][j] = 0;

  cout << "\n";
  // write old array into new
  for (int i = 0; i < height; i++)
    newA[i][0] = array[i][0];

  for (int i = 0; i < height; i++)
  {

    for (int j = 1; j < width; j++)
    {
      newA[i][j % 2 == 1 ? j + (j - 1) / 2 : j + j / 2] = array[i][j];
    }
  }

  printArray(newA, height, newW);
}

int main()
{

  // std::string str = "The something awesome \"string\" about \"quotes sdfsfgdfgdf sdsdf 123\"";

  // std::cout << str << "\n";

  std::regex reg2("(\"[\\w || \\s]*\")");

  // PrintMatches(reg2, "myfile.txt");
  PrintArrays();
  return 0;
}