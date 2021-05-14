#include <iostream>
#include <string>
#include <vector>

#define ll long long 

using namespace std;

int main()
{	
  int n;
  cin>>n;
  unsigned int x = 0, a;
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    x = x ^ a;
  }
  cout<<x;
	return 0;
}