#include <iostream>
#include <limits>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  ll T;
  cin >>T;
  ll NG, NM;
  while(T--) {
    cin>>NG>>NM;
    ll maxG = std::numeric_limits<int>::min();
    ll maxM = maxG;
    ll power;
    for(ll i = 0; i< NG; i++) {
      cin>>power;
      if (power > maxG) maxG = power;
    }
    for(ll i = 0; i< NM; i++) {
      cin>>power;
      if (power > maxM) maxM = power;
    }
    if (maxG < maxM) cout<<"MechaGodzilla"<<endl;
    else cout<<"Godzilla"<<endl;
  }
	return 0;
}