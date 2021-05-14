#include <iostream>

#define ll long long 

using namespace std;

int main()
{	
	while(1)
  {
    float h;
    cin>>h;
    if (h == 0) break;
    long double sum = 0;
    for(float i = 0;;i++) {
      sum = sum +  (1/(i+2));
      if (sum > h) {
        cout<<i + 1<<" card(s)"<<endl;
        break;
      }
    }
  }
	return 0;
}