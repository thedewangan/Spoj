#include <iostream>
#include <cmath>
#include <vector>

#define ll unsigned long long

using namespace std;


int main()
{	
  ll T;
  cin>>T;
  while(T--) {
    ll n, k ,m;
    cin>>n>>k>>m;
    if (m<n) cout<<0<<endl;
    else {
      ll t = log(m/n)/log(k);
      ll check = pow(k, t);
      if ( t >= 1) {
        if(check == m/(k*n) ) t++;
        cout<<t<<endl;
      } else if (n == m/k) t++;

    }
  }
	return 0;
}