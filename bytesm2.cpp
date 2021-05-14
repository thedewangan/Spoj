#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 

using namespace std;

int maximum(int a, int b, int c) {
  return max(max(a, b), c);
}

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int row, col;
    cin>>row>>col;
    vector < vector<int> > mat;
    mat.resize(row);
    for(int i = 0; i < row; i++) mat[i].resize(col, 0);
  
    for(int i = 0; i < row; i++ ) {
      for(int j = 0; j < col; j++) 
        cin>>mat[i][j];
    }
  
    int inc = 0;
    for(int i = row - 2; i >= 0; i-- ) {
      for(int j = 0; j < col; j++) {
        if(j-1 >= 0 && j+1 < col ) inc = maximum(mat[i+1][j-1], mat[i+1][j], mat[i+1][j+1]);
        else if (j-1 >=0) inc = max(mat[i+1][j-1], mat[i+1][j]);
        else if (j+1 < col) inc = max(mat[i+1][j], mat[i+1][j+1]);
        else inc = mat[i+1][j];
  
        mat[i][j] += inc;
      }
    }
    int max = -1;
    for(int j = 0; j < col; j++)
      if(mat[0][j] > max) max = mat[0][j];
    cout<<max<<endl;
  }
}