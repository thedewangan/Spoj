#include <iostream>
#include <string>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  ll n;
  int ans;
  cin>>n;
  if (n%10 == 0) cout<<2<<"\n";
  else cout<<1<<"\n"<<n%10<<endl;
 	return 0;
}