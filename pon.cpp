#include <iostream>
#include <math.h>
#include <vector>

#define ll unsigned long long 

using namespace std;

// smallest prime factor
void fill(vector<ll> &prime, ll n) {
  for(ll i = 2; i <= n; i++) {
    if (prime[i]) {
      for(ll j = 2; i*j <= n; j++ ) {
        prime[i*j] = 0;
      }
    }
  }
}

int main()
{	
  ll T;
  cin>>T;

  ll inp[T];
  ll max = -1;
  vector <ll> dp, prime;

  for(ll i = 0; i < T; i++) {
    cin>>inp[i];
    if(inp[i] > max) max = inp[i];
  }
  
  //cout<<max<<endl;
  prime.resize(max + 1, 1);

  fill(prime, max);
  for(ll i = 0; i < T; i++) {
    if(prime[inp[i]]) cout<<"YES\n";
    else cout<<"NO\n";
  }


	return 0;
}