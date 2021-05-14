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

  while(1) {
    string str1, str2;
    cin>> str1 >> str2;
    if(str1.length() == 1 && str2.length() == 1 && str1[0] == '*' && str2[0] == '*')
      break;
    int r = str1.length() + 1;
    int c = str2.length() + 1;

    vector < vector<int> > dp;
    dp.resize(r);
    for(int i = 0; i < r; i++) dp[i].resize(c, 0);

    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        int cost = 0;
        if(i == 0) dp[i][j] = j;
        else if(j == 0) dp[i][j] = i;
        else {
          if (str1[i-1] == str2[j-1]) cost = 0;
          else cost = 1;
            
          dp[i][j] = minimum(1 + dp[i-1][j], dp[i-1][j-1] + cost, 1 + dp[i][j-1]);
  
          if (i > 1 && j > 1 && str1[i-1] == str2[j-2] && str1[i-2] == str2[j-1]) {
            dp[i][j] = min(dp[i][j], dp[i-2][j-2] + cost);
          }
        }

      }
    }
      //cout<<endl;
    cout<<dp[r-1][c-1]<<endl;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}