#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	

  while(1) {
    ll n;
    cin>>n;
    if(!n) break;
    cout<<(n*(n+1)*(2*n+1))/6<<endl;
  }
	return 0;
}