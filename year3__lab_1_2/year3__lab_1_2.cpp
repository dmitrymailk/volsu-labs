#include "./lab_files/vector.cpp"

int main()
{
  vector<int> vec;
  vec.push(1);
  vec.push(2);
  vec.push(25);
  vec.show_all();

  vector<const char *> vec2;
  vec2.push("hello");
  vec2.push("it's");
  vec2.push("me");
  vec2.push("me");
  vec2.show_all();
  vec2.pop();
  vec2.show_all();
  vector<int> copy_vec = vec;
  copy_vec.show_all();
}