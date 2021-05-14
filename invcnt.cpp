#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long 

using namespace std;

void mergesort (int *a, int l, int h, ll &inversions) {
  // cout<<"sorting elements: \t";
  // for(int i = l; i <= h; i++) cout<<a[i];
  // cout<<endl;

  if (h == l) return;
  int m = l + (h-l)/2;
  int sizeB = m-l+1;
  int sizeC = h-m;
  int *b, *c;
  //cout<<sizeB<<" "<<sizeC;
  b = new int[sizeB];
  c = new int[sizeC];
  for(int i = l; i <=m; i++) {
    b[i-l] = a[i];
  }
  for(int i = m+1; i <=h; i++) {
    c[i-m-1] = a[i];
  }
  
  mergesort(b, 0 , sizeB-1, inversions);
  mergesort(c, 0, sizeC-1, inversions);

  int apos = 0;
  int *bInit = b;
  int *cInit = c;
  while(sizeB && sizeC) {
    if (b[0] <= c[0]) {
      a[apos] = b[0];
      sizeB--;
      b++;
    }
    else {
      inversions += sizeB;
      // for(int i = 0; i < sizeB; i++)
      //   cout<<b[i]<<" "<<c[0]<<endl;
      a[apos] = c[0];
      sizeC--;
      c++;
    }
    apos++;
  }
  //cout<<sizeB<<" "<<sizeC<<endl;
  // for(int i = 0; i < apos; i++) cout<<a[i];

  int * rmndr;
  int s;
  if(sizeB) {
    rmndr = b;
    s = sizeB;
  } else {
    rmndr = c;
    s = sizeC;
  }
  
  for(int i = 0; i < s; i++) {
    a[i+apos] = rmndr[i];
  }

  //for(int i = 0; i < 5; i++) cout<<a[i];

  delete[] bInit;
  delete[] cInit;
  b = NULL;
  c = NULL;
}

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    ll inversions = 0;
    mergesort(a, 0, n - 1, inversions);
    
    //for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    cout<<inversions;
    cout<<endl;
  }
}