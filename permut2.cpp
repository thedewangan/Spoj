#include <iostream>
#include <limits>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  int n;
  while(1) {
    cin >> n;
    if (n == 0) return 0;
    int perm[n];
    int inverse[n];
    int t;
    for(int i = 1; i <= n; i++) {
      cin >> t;
      perm[i - 1] = t;
      inverse[t-1] = i;
    }
    int amb = 1;
    for(int i = 0; i < n; i++) {
      if (perm[i] != inverse[i]) {
        amb = 0;
        break;
      }
    }
    if (amb) cout<<"ambiguous\n";
    else cout <<"not ambiguous\n";
  }
	return 0;
}