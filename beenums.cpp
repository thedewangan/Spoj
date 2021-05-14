#include <iostream>
#include <string>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  ll n, p;
  bool ans;
  while(1) {
    cin>>n;
    if(n == -1) return 0;
    if (n == 1) ans = true;
    else if ((n-1)%3 != 0) ans = false;
    else {
      p = sqrt((n - 1)/3);
      //cout<<"Number and root "<<n<<" "<<p<<endl;
      if (p * (p + 1) == (n - 1)/3) ans = true;
      else ans = false;
    }
    if (ans) cout<<"Y\n";
    else cout<<"N\n";
  }
	return 0;
}