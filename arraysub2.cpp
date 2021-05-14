#include <iostream>
#include <deque>
#include <vector>

#define ll long long 

using namespace std;

/* using deque */

int main()
{	
  int n, k;
  scanf("%d", &n);
  int *a = new int[n];
  int maxPos = 0;
  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }
  cin>>k;

  // for(int i = 1; i < k; i++) {
  //   if(a[i] > a[maxPos]) {
  //     maxPos = i;
  //   }
  // }

  deque <int> q;
  //q.push_front(0);

  int start = 0;

  for(int cur = 0; cur < n; cur++) {
    if(!q.empty() && q.front() <= cur - k) {
      //cout<<"Removing index: "<<q.front()<<endl;
      q.pop_front();
    }
    while(!q.empty() && (a[q.back()] < a[cur])) {
      q.pop_back();
    }
    //cout<<"Pushing back index: "<<cur<<endl;
    q.push_back(cur);
    if(cur >= k - 1) cout<<a[q.front()]<<" ";

  }

  delete [] a;
	return 0;
}