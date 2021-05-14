#include <iostream>
#include <math.h>
#include <vector>

#define ll long long 

using namespace std;

// smallest prime factor
void fill(vector<ll> &primeFactor, int n) {
  for(ll i = 2; i <= n; i++) {
    if (!primeFactor[i]) {
      for(ll j = 1; i*j <= n; j++ ) {
        if(!primeFactor[i*j]) primeFactor[i*j] = i;
      }
    }
  }
}

int main()
{	
  int T;
  cin>>T;

  int inp[T];
  int max = -1;
  vector <ll> dp, primeFactor;

  for(int i = 0; i < T; i++) {
    cin>>inp[i];
    if(inp[i] > max) max = inp[i];
  }
  
  dp.resize(max + 1, 0);
  primeFactor.resize(max + 1, 0);

  fill(primeFactor, max);

  for(int i = 2; i <= max; i++) {
    dp[i] = dp[i-1] + primeFactor[i];
  };

  // for(int i = 2; i <= max; i++) {
  //   cout<<primeFactor[i]<<" ";
  // };
  // cout<<endl;
  // for(int i = 2; i <= max; i++) {
  //   cout<<dp[i]<<" ";
  // };

  for(int i = 0; i < T; i++) {
    cout<<dp[inp[i]]<<endl;
  }

	return 0;
}