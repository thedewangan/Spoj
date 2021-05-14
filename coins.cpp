#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define ll long long 

using namespace std;

ll maximum(int a, ll b) {
  if(a > b) return a;
  else return b;
}
unordered_map <int, ll> m;

ll maxCoins(int n) {
  if(m.find(n) != m.end()) return m[n];
  else {
    m[n] = maximum(n, maxCoins(n/2) + maxCoins(n/3) + maxCoins(n/4));
    return m[n];
  }
}

int main()
{	
  int n;
  m[0] = 0;
  while(scanf("%d", &n) != EOF) {
    ll  ans;
    cout<<maxCoins(n)<<endl;
  }
	return 0;
}