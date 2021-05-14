#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  ll a, b, c, x;
  while(1) {
    cin>>a>>b>>c;
    if(!a && !b && !c) return 0;
    if (c-b == b-a) cout<<"AP "<<c+(b-a)<<endl;
    else cout<<"GP "<<c*(b/a)<<endl;
  }
	return 0;
}