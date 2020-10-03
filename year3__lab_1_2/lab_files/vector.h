
#ifndef MY_VECTOR
#define MY_VECTOR
template <class T>
class vector
{
private:
  T *buffer;
  int size;
  int capacity;

public:
  vector();
  vector<T> &operator=(const vector<T> &v)
  {
    delete[] buffer;
    size = v.size;
    capacity = v.capacity;
    buffer = new T[size];
    for (int i = 0; i < size; i++)
      buffer[i] = v.buffer[i];
    return *this;
  }
  void push(T);
  void show_all();
  void pop();
};

#endif