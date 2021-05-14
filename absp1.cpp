#include <iostream>
#include <algorithm>
#include <math.h>


#define ll long long 

using namespace std;


int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    ll sum = 0;
    int end = n;
    int size = n;
    for(int i = 0; i < n/2; i++) {
      sum += (a[n-i-1] - a[i]) * (size-1);
      end--;
      size = size - 2;
    }
    cout<<sum<<endl;
  }

	return 0;
}