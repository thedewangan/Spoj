#include <iostream>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  ll T;
  cin >>T;
  ll x;
  while(T--) {
    cin>>x;
    //n^2 + n - x = 0
    int line;
    ll sol1 = (-1 + sqrt(1 + 8 * x))/2;
    // float sol2 = (-1 - root(1 + 4  * 2*num))/2;
    line = sol1;
    int lastVal = (line * (line + 1)) / 2;
    int extra = x - lastVal;
    int num, den;
    if (extra == 0) {
      num = line;
      den = 1;
    }
    else if (extra == 1) {
      num = line + 1;
      den = 1;
    }
    else {
      num = line + 1 - (extra - 1);
      den = 1 + extra - 1;
    }

    if (line % 2 != 0) {
      int temp = num;
      num = den;
      den = temp;
    }
    cout<<"TERM "<<x<<" IS "<<num<<"/"<<den<<endl;
  }
	return 0;
}