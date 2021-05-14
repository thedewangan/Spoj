#include <iostream>
#include <algorithm>
#include <vector>


#define ll long long 

using namespace std;


int main()
{	
  int r;
  int ctr = 1;
  while(1) {
    cin>>r;
    if(!r) break;
    vector <vector <ll> > mat;
    mat.resize(r);
    for(int i = 0; i < r; i++) {
      mat[i].resize(3);
      for(int j = 0; j < 3; j++) {
        cin>>mat[i][j];
        if(i == 1) {
          if (j==0) mat[i][j] += mat[0][1];
          else if(j==1) mat[i][j] = mat[i][j] + min(mat[i][j-1], min(mat[0][1], mat[0][1] + mat[0][2]));
          else mat[i][j] = mat[i][j] + min(mat[i][j-1], min(mat[0][1], mat[0][1] + mat[0][2]));
        }
        else if(i > 1) {
          if(j==0) mat[i][j] = mat[i][j] + min(mat[i-1][j], mat[i-1][j+1]);
          else if(j==1) mat[i][j] = mat[i][j] + min(min(mat[i][j-1], mat[i-1][j-1]), min(mat[i-1][j], mat[i-1][j+1]));
          else if(j==2) mat[i][j] = mat[i][j] + min(mat[i][j-1], min(mat[i-1][j], mat[i-1][j-1]));
        } 
      }
    }
    // for(int i = 0; i < r; i++) {
    //   for(int j = 0; j < 3; j++) {
    //     cout<<mat[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    // cout<<endl;

    cout<<ctr++<<". "<<mat[r-1][1]<<endl;
  }
	return 0;
}