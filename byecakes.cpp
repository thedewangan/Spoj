#include <iostream>
#include <vector>
#include <math.h>

#define ll long long 

using namespace std;


int main()
{	
  while(1) {
    long double ing[4];
    long double req[4];
    //double cake[4];
    for(int i = 0; i < 4; i++) {
      cin>>ing[i];
      if(ing[i] == -1) return 0;
    }
    for(int i = 0; i < 4; i++) {
      cin>>req[i];
    }
    ll max = -1;
    for(int i = 0; i < 4; i++) {
      long double tmp = ceil(ing[i]/req[i]);
      if(tmp > max) max = tmp;
    }
    //cout<<max<<endl;
    max = ceil(max);
    //cout<<max<<endl;
    for(int i = 0; i < 4; i++) {
      ll r = max*req[i];
      cout<< r - ing[i]<<" ";
    }
    cout<<"\n";

  }

	return 0;
}