#include <iostream>
#include <string>


#define ll long long 

using namespace std;


int main()
{	
  int T;
  cin>>T;
  while(T--) {
    string str;
    cin>>str;
    int flag = 1;
    for(int i = 0; i < str.length()/2; i++) {
      if(str[i] != str[str.length()-i-1]) {
        flag = 0;
        break;
      }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
  }
	return 0;
}