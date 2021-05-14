#include <iostream>
#include <limits>
#include <math.h>

#define ll long long 
long double pi = 3.1416;
using namespace std;

int main()
{	
  long double L;
  while(1) {
    cin >> L;
    if (L == 0) return 0;
    long double area = pow(L, 2)/(2*pi);
    printf("%0.2Lf\n", area); 
  }
	return 0;
}