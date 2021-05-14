#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  ll T;
  cin>>T;
  while(T--) {
    ll n, c;
    cin>>n>>c;
    ll a[n];
    ll start = 0, end = -1;
    ll sum = 0, seen = 0;

    for(ll i = 0; i < n; i++) {
      cin>>a[i];
      sum += a[i];
      if (sum <= c) {
        //cout<<"Increasing window\n";
        end++;
        seen = sum;
      } else {
        //cout<<"Shifting window\n";
        sum -= a[start] ;
        if (sum < seen) seen = sum;
        end++;
        start++;
      }
    }
    ll stations = end-start+1;
    cout<<seen<<" "<<stations<<endl;
  }
	return 0;
}