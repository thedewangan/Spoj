#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int count_setbits(int N)
{ 
  int cnt = 0;
  while(N > 0)
  {
    N = N & (N-1);
    cnt++;
  }
  return cnt;
}

int main()
{	
  int T, n;
  vector < vector<int> > mat;
  vector <ll> dp;
  cin>>T;
  while(T--) {
    cin>>n;
    mat.resize(n);
    dp.resize(pow(2, n), 0);
    memset(&dp[0], 0, sizeof(dp[0]) * dp.size());
    for(int i = 0; i < n; i++) {
      mat[i].resize(n);
      for(int j = 0; j < n; j++){
        cin>>mat[i][j];
      }    
    }

    dp[0] = 1;

    for(int mask = 0; mask < pow(2, n); mask++) {
      for(int j = 0; j < n; j++) {
        int t = n - j - 1;
        int k = __builtin_popcount(mask); //count_setbits(mask);
        if(!(mask&(1<<t)) && mat[k][j] == 1) {
          dp[mask|(1<<t)] = dp[mask|(1<<t)] + dp[mask];
        }
      }
    }
    ll last = pow(2, n) - 1;
    cout<<dp[last]<<endl;

  }
	return 0;
}