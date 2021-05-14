#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define ll long long 

using namespace std;

int main()
{	
  int n;
  cin>>n;
  vector <char> v1, v2;
  v1.resize(2*n);
  //v2.resize(2*n);
  char c;
  for(int i = 0; i< 2*n; i++) {
    cin>>v1[i];
    //cout<<v1[i]<<" ";
  }
  //cout<<endl;

  for(int i = 0; i< 2*n; i=i+2) {
    vector <char> t;
    if ((v1[i] != 'A') && (v1[i+1] != 'A')) t.push_back('A');
    if ((v1[i] != 'B') && (v1[i+1] != 'B')) t.push_back('B');
    if ((v1[i] != 'C') && (v1[i+1] != 'C')) t.push_back('C');
    if ((v1[i] != 'D') && (v1[i+1] != 'D')) t.push_back('D');
    //cout<<"size of t "<<t.size()<<endl;
    if(i==0) {
      v2.push_back(t[0]);
      v2.push_back(t[1]);
    }
    else {
      if (v2[i-1] != t[0]) {
        v2.push_back(t[0]);
        v2.push_back(t[1]);
      } else {
        v2.push_back(t[1]);
        v2.push_back(t[0]);
      }
    }
  }
  //cout<<"size of v2: "<<v2.size()<<endl;
  for(int i = 0; i< 2*n; i++) {
    cout<<v2[i];
  }

	return 0;
}