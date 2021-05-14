#include <iostream>

#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int n;
    cin>>n;
    int sum = 0;
    int l = round(log(n)/log(5));
    for(int i = 1; i <= l; i++) {
      sum += n/pow(5, i);
    }
    cout<<sum<<endl;
  }
	return 0;
}