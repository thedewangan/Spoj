#include <iostream>
#include <math.h>
#include <vector>
#include <limits>

#define ll long long 

using namespace std;

int main()
{	
	while(1)
  {
    int A, D;
    cin>>A>>D;
    if (A == 0 && D == 0) break;
    // int attackerDist[A];
    // int defenderDist[D];
    int dist;
    int minA= std::numeric_limits<int>::max();
    int minB1 = std::numeric_limits<int>::max();
    int minB2 = minB1;

    for(int i = 0; i < A; i++) {
      cin>>dist;
      if (dist < minA) minA = dist;
    }
    for(int i = 0; i < D; i++) {
      cin>>dist;
      // minB2 is greater or equal than minB1
      if (dist < minB1) {
        minB2 = minB1;
        minB1 = dist;
      } 
      else if(dist < minB2) {
        minB2 = dist;
      }
      //cout<<" "<<minB1<<" "<<minB2<<endl;
    }
    //cout<<minA<<" "<<minB1<<" "<<minB2;
    if (minA < minB2) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
  }
	return 0;
}