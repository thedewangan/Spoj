#include <iostream>
#include <algorithm>
#include <math.h>


#define ll long long 

using namespace std;


int main()
{	
  int T;
  scanf("%d", &T);
  while(T--) {
    ll n;
    long double ans;
    scanf("%lld", &n);
    ans = floor(n/2);
    ans = ceil(ans/2);
    ll b = ans;
    //cout<<n<<" : "<<b<<endl;
    printf("%lld\n", b);
  }

	return 0;
}