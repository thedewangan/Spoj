#include <iostream>
#include <vector>
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
    vector <int> m, w;
    m.resize(n);
    w.resize(n);
    for(int i = 0; i < n; i++) cin>>m[i];
    for(int i = 0; i < n; i++) cin>>w[i];
    sort(w.begin(), w.end());
    sort(m.begin(), m.end());
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += w[i]*m[i];
    }
    cout<<sum<<endl;
  }
	return 0;
}