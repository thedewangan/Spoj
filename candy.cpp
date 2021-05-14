#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  while(1) {
    int n;
    cin>>n;
    if(n == -1) return 0;
    int sum = 0;
    int c[n];
    for(int i = 0; i < n; i++) {
      cin>>c[i];
      sum+=c[i];
    }
    if(sum%n != 0) cout<<"-1"<<endl;
    else {
      int avg = sum/n;
      int move = 0;
      for(int i = 0; i < n; i++) {
        if(c[i] < avg) move+= avg - c[i];
      }
      cout<<move<<endl;
    }
  }
	return 0;
}