#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int r[10] = {0, 1, 4, 4, 2, 1, 1, 4, 4, 2};
int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int a, b;
    cin>>a>>b;
    a = a%10;
    if (a == 0) {
      cout<<0<<endl;
      continue;
    } else if (b == 0) {
      cout<<1<<endl;
      continue;
    }

    b = b%r[a];
    if (b == 0) b = r[a];
    int t = pow(a, b);
    cout<<t%10<<endl;
  }
	return 0;
}