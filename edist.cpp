#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long 

using namespace std;

int minimum(int a, int b, int c) {
  return min(min(a, b), c);
}

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    string str1, str2;
    cin>> str1 >> str2;
    int r = str1.length() + 1;
    int c = str2.length() + 1;

    vector < vector<int> > dp;
    dp.resize(r);
    for(int i = 0; i < r; i++) dp[i].resize(c, 0);

    for(int i = 0; i < r; i++) dp[i][0] = i;
    for(int j = 0; j < c; j++) dp[0][j] = j;

    for(int i = 1; i < r; i++) {
      for(int j = 1; j < c; j++) {
        //cout<<dp[i][j]<<" ";
        if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = 1 + minimum(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
      }
      //cout<<endl;
    }
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<dp[r-1][c-1]<<endl;
  }
}