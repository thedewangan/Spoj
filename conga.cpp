#include <iostream>
#include <algorithm>
#include <vector>


#define ll long long 

using namespace std;


int main()
{	
  while(1) {
    int n;
    vector <ll> v;
    scanf("%d", &n);
    if(!n) break;
    ll x;
    for(int i = 0; i < n; i++) {
      scanf("%lld", &x);
      v.push_back(x);
    }
    int m = n/2;
    int e = 1;
    ll gap, steps = 0;
    //cout<<m<<endl;
    for(int i = 0; i < m; i++) {
      gap = v[i+1] - v[i] - 1;
      steps += e * gap;
      e++;
    }
    //cout<<steps<<endl;
    e = 1;
    for(int i = n-1; i > m; i--) {
      gap = v[i] - v[i-1] - 1;
      steps += e * gap;
      e++;
    }
    printf("%lld\n", steps);
  }
	return 0;
}