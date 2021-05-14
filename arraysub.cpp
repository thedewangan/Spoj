#include <iostream>
#include <math.h>
#include <vector>

#define ll long long 

using namespace std;

/*BRUTE FORCE */
int main()
{	
  int n, k;
  scanf("%d", &n);
  int *a = new int[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &k);
  for(int i = 0; i <= n - k; i++) {
    int max = -10000000;
    for(int j = i; j <i + k; j++) {
      if(a[j] > max) max = a[j];
    }
    printf("%d ", max);
  }
  delete [] a;
	return 0;
}