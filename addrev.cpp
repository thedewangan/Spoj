#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

ll reverse2(int num) {
  int digits = 0;
  int n = num;
  while(n) {
    n = n/10; //pow(10, digits+1);
    digits++;
  }
  ll rev = 0;
  int i = 1;
  cout<<digits<<endl;
  while(digits--) {
    rev += (num%10) * pow(10, digits);
    num = num/10;
    i++;
  }
  return rev;
}

ll reverse(int num) {
  ll rev = 0;
  while(num) {
    rev = rev*10 + num%10;
    num = num/10;
  }
  return rev;
}

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int a, b;
    cin>>a>>b;
    cout<<reverse(reverse(a)+reverse(b))<<endl;
  }
	return 0;
}