#include <iostream>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  ll T;
  ll x, y, z, n, d, a;
  cin>>T;
  for(ll i = 0; i < T; i++) {
    cin>>x>>y>>z;
    n = (2*z)/(x+y);
    d = (y - x)/(n - 5);
    a = x - 2*d;
    ll j = 0;
    cout<<n<<"\n";
    while(j < n) {
      cout<<a<<" ";
      a = a + d;
      j++;
    }
  
    cout<<"\n";
  }

  return 0;
}