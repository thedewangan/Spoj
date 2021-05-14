#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  int n;
  cin>>n;
  int sum = 0;
  for (int i = 1; ; i++) {
    int inc = (n/i) - (i-1);
    if (inc > 0) sum+=inc;
    else break;
  }
  cout<<sum;
	return 0;
}