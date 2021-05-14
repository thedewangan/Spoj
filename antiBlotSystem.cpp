#include <iostream>
#include <string>

#define ll long long 

using namespace std;

bool containsMachula(string s) {
  for(int i = 0; i < s.length(); i++) {
    if (s[i] < '0' || s[i] > '9'){
      return true;
    } 
  }
  return false;
}

int main()
{	
  ll T;
  string A, B, C, sign1, sign2;
  int nm1, nm2;
  cin >>T;
  string X;
  while(T--) {
    cin>>A>>sign1;
    cin>>B>>sign2;
    cin>>C;
    char cs;
    if (containsMachula(A)) {
      cs = 'A';
      X = A;
      nm1 = -1 * stoi(B);
      nm2 = stoi(C);
    }
    else if (containsMachula(B)) {
      cs = 'B';
      X = B;
      nm1 = -1 * stoi(A);
      nm2 = stoi(C);
    }
    else {
      cs = 'C';
      X = C;
      nm1 = stoi(A);
      nm2 = stoi(B);
    }
    //nm1 + nm2 = X;
    int u = nm1 + nm2;
    switch(cs) {
      case 'A': cout<<u<<" + "<<B<<" = "<<C<<endl; break;
      case 'B': cout<<A<<" + "<<u<<" = "<<C<<endl; break;
      case 'C': cout<<A<<" + "<<B<<" = "<<u<<endl; break;
    }
  }
	return 0;
}