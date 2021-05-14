#include <iostream>
#include <string>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  ll n, p;
  int T;
  cin>>T;
  while(T--) {
    cin>>n;
    cout<<((n*(3*n+1))/2)%1000007<<endl;
  }
	return 0;
}