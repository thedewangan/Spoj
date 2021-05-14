#include <iostream>
#include <vector>

using namespace std;

struct Person{
  string name;
  int age;
};

int main() {
  Person p1, p2;
  p1.name = "ab";
  p1.age = 5;

  p2.name = "cd";
  p2.age = 4;

  vector<int> v1{1, 2};
  vector<int> v2{3, 4};

  cout<<(v1>v2);
  return 0;
}