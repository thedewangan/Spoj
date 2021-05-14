#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

// predicate - with x as minimum diff, C cows are NOT able to fit
bool p(int x, vector<unsigned int> s, int C) {
  int cowsAccomodated = 1;
  int latestStall = 0;
  for(int i = 1; i < s.size(); i++) {
    if(s[i] - s[latestStall] >= x) {
      cowsAccomodated++;
      latestStall = i;   
      if(cowsAccomodated == C) return false;
    }
  }
  return true;
}

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int N, C;
    cin>>N>>C;
    vector<unsigned int> s;
    s.resize(N);
    for(int i = 0; i < N; i++) cin>>s[i];
    sort(s.begin(), s.end());

    //cout<<p(4, s, 3);
    int lo, hi;
    lo = 0;
    hi = *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()); 
    // cout<<lo<<" "<<hi;
    while(lo < hi) {
      int x = lo + (hi - lo + 1)/2;
      if(p(x, s, C) == true) hi = x - 1;
      else lo = x;
    }
    // if (p(x) == true) no diff found
    cout<<lo<<endl;
  }
	return 0;
}