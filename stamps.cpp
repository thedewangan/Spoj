#include <iostream>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  ll T;
  int needed;
  int numFriends;
  cin >>T;
  ll s = 1;
  while(T--) {
    cin >> needed >> numFriends;
    int stamps[numFriends];
    for(int i = 0; i< numFriends; i++) cin>>stamps[i];
    sort(stamps, stamps + numFriends);
    int sum = 0;
    for(int i = numFriends - 1; i >= 0; i--) {
      sum = sum + stamps[i];
      if (sum >= needed) {
        cout<<"Scenario #"<<s<<":\n";
        cout<<numFriends - i<<"\n\n";
        break;
      }
    } 
    if (sum < needed) cout<<"Scenario #"<<s<<":\n"<<"impossible\n\n";
    s++;
  }
	return 0;
}