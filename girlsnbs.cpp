#include <iostream>
#include <limits>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  long double a, b, min, max;
  while(1) {
    cin >> a >> b;
    long double ans;
    if (a == -1 && b == -1) return 0;
    if (a == 0) ans = b;
    else if (b == 0) ans = a;
    else if(a == b) ans = 1;
    else {
      if (a > b) {min = b; max = a;}
      else {min = a; max = b;}
      ans = max/(min + 1);
      ans = ceil(ans);
    }
    cout<<ans<<"\n";
    
  }
	return 0;
}