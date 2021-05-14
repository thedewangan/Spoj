#include <iostream>
#include <math.h>

#define ll long long 

using namespace std;

int main()
{	
  int T;
  ll n, up, down=0;
  cin>>T;
  for(int i = 0; i < T; i++) {
    cin>>n;
    up = (((n*(n+1)*(2*n+1))/6) + ((3*n*(n+1))/2) - (2*n))/2;
    if (n>=4 && n%2==0) down = pow((n/2)-1, 2);
    else if(n>4 && n%2!=0) down = ((n-1)*(n-3))/4;

    cout<<n<<" : "<<down<<"\n";
  }
  return 0;
}