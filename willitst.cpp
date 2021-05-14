#include <iostream>

#define ll long long 

using namespace std;

int main()
{	
  ll num;
  cin>>num;
  while(num > 1) {
    if ((num % 2) == 0) num = num/2;
    else {
      cout<<"NIE"<<"\n";
      return 0;
    }
  }
  cout<<"TAK"<<"\n";
	return 0;
}