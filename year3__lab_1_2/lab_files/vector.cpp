#include <iostream>
using namespace std;
#include "vector.h"

template <class T>
vector<T>::vector()
{
  buffer = new T[1];
  capacity = 1;
  size = 0;
};

template <class T>
void vector<T>::push(T item)
{
  if (size == capacity)
  {
    T *temp = new T[2 * capacity];

    // copying old array elements to new array
    for (int i = 0; i < capacity; i++)
      temp[i] = buffer[i];

    // deleting previous array
    delete[] buffer;
    capacity *= 2;
    buffer = temp;
  }

  // Inserting data
  buffer[size] = item;
  size++;
};

template <class T>
void vector<T>::show_all()
{
  for (int i = 0; i < size; i++)
  {
    cout << buffer[i] << "\n";
  }
  cout << "-----------"
       << "\n";
};

template <class T>
void vector<T>::pop()
{
  T *temp = new T[2 * capacity - 1];

  // copying old array elements to new array
  for (int i = 0; i < 2 * capacity - 1; i++)
    temp[i] = buffer[i];

  // deleting previous array
  delete[] buffer;
  capacity = 2 * capacity - 1;
  buffer = temp;
  size--;
};
