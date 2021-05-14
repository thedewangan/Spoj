#include <iostream>
#include <string>
#include <vector>

#define ll long long 

using namespace std;

int main()
{	
  string n, ans;

  ll ctr = 0;
  while(cin>>n) {
    // cin >> n;
    vector <int> v1, v2, v3;
    int l = n.length();
    v1.resize(l+1, 0);
    v2.resize(l+1, 0);
    v3.resize(l+1, 0);

    if (l == 1 && (n[0] == '1')) {
      v3[1] = 1;
      //continue;
    }
    else {
      //cout<<l<<endl;
      v3[l] = 2;
      for(int i = 1; i <=l; i++){
        v1[i] = n[i-1] - 48;
        v2[i] = n[i-1] - 48;
        //cout<<v1[i];
      }
      int sum = 0, carry = 0;
      for(int i = 0; i <= l; i++){
      sum = carry + v1[l-i] + v2[l-i];
      v2[l-i] = sum%10;
      carry = sum/10;
      }

      // for(int i = 0; i <=l; i++){
      //   cout<<v2[i];
      // }
      // cout<<endl;

      int dif = 0;
      for(int i = 0; i <= l; i++) {
      if (dif < 0) v2[l-i]--;
      dif = v2[l-i] - v3[l-i];
      if (dif < 0) v3[l-i] = dif + 10;
      else v3[l-i] = dif;
      }
      
    }

    if(v3[0] == 0) v3.erase(v3.begin(), v3.begin()+1);
    if (ctr != 0)  cout<<endl;
    for(int i = 0; i < v3.size(); i++){
      cout<<v3[i];
    }
    ctr++;
   
  }
	return 0;
}