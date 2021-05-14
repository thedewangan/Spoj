#include <iostream>
#include <stack>

#define ll long long 

using namespace std;

int main()
{	
  int n;
  while(1) {
    cin >> n;
    if (n==0) return 0;
    int t;
    stack <int> s, s1, s2, s3;
    for(int i = 0; i < n; i++) {
      cin>>t;
      //cout<<t<<"\n";
      s.push(t);
    }
    for(int i = 0; i < n; i++) {
      s1.push(s.top());
      s.pop();
    }

    int t1, t2, t3, flag = 0;
    while(s3.size() != n) {
      // s1 -> s3
      if (s1.size() && (s1.top() == 1 || (s3.size() && s1.top() == s3.top() + 1)) ) {
        //cout<<"s1 to s3\n";
        s3.push(s1.top());
        s1.pop();
      } else if (s2.size() && s3.size() && s2.top() == s3.top() + 1) {
        // s2 -> s3
        //cout<<"s2 to s3\n";
        s3.push(s2.top());
        s2.pop();
      } else if (s1.size() && ((s2.size() && s2.top() > s1.top()) || s2.size() == 0 )) {
        // s1 -> s2
        //cout<<"s1 to s2\n";
        s2.push(s1.top());
        s1.pop();
      } else {
        //cout<<"breaking";
        flag = 1;
        break;
      }
    }
    if (flag) cout<<"no\n";
    else cout<<"yes\n";
  }
	return 0;
}