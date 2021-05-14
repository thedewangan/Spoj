#include <iostream>
#include <stdlib.h>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    string get_first_name()  {
      return first_name_;
    }
    string& get_last_name() {
      return last_name_;
    }
    int foo() {
      return 1;
    }
    string& foo2() {
      int a = rand()%10;
      string s = to_string(a);
      cout<<s<<endl;
      return s;
    }
private:
    string first_name_;
    string last_name_;
};
// Enter your code here.
ostream& operator << (ostream& out, Person& p) {
  // both below statements work
    p.get_first_name() = "";
    p.get_last_name() = "";
    // below will not work. Since foo returns an inbuilt datatype, it is kind of value (?) not variable
    // while above two were kind of variables since they were userdefined/abstract datatype
    // above 2 won't work only if you mention const string and const string& as return types
    // https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter08_014.html
    //p.foo() = 2;
    

    cout<<p.foo2()<<endl;
    // above line is going to print garbage since foo2 is returning reference to a variable which goes
    // out of scope after returnin
    out<<"first_name="<<p.get_first_name()<<",last_name="<<p.get_last_name();
    return out;
}


int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}
