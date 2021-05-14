#include <iostream>
#include <algorithm>
#include <vector>


#define ll long long 

using namespace std;


vector < pair<int, int> > getNeighbours(int i, int j, int h, int c, vector< vector<char> > &mat){ 
  vector< pair <int,int> > neighbours;
  for(int x=-1; x <=1; x++) {
    for(int y =-1; y<=1; y++) {
      int u = i+x;
      int v = j+y;
      if((u!=i || v!=j) && u >= 0 && u < h && v>=0 && v < c) {
        if (mat[u][v] == mat[i][j] + 1){
          //cout<<u<<" "<<v<<endl;
          neighbours.push_back(make_pair(u, v));
        }
      }
    }
  }
  //cout<<"Neighbour size "<<neighbours.size()<<endl;
  return neighbours;
}
int dfs(int i, int j, int h, int c, vector < vector<int > > &dp, vector< vector<char> > &mat) {
  if(dp[i][j]) return dp[i][j];
  //cout<<"In dfs\t"<<i<<" "<<j<<endl;
  vector < pair<int, int> > v;
  v = getNeighbours(i, j, h, c, mat);
  //cout<<v.size()<<endl;
  int max = 1;
  for(int x = 0; x < v.size(); x++) {
    int p = 1 + dfs(v[x].first, v[x].second, h, c, dp, mat);
    if (p > max) max = p;
  }
  dp[i][j] = max;
  return max;
} 

int main()
{	
  int h, c;
  // width is c
  int ctr = 0;
  while(1) {
    cin>>h>>c;
    if(!h && !c) break;
    vector < vector<int > >dp;
    vector< vector<char> > mat;
    mat.resize(h);
    dp.resize(h);
    for(int i = 0; i < h; i++) {
      mat[i].resize(c);
      dp[i].resize(c, 0);
      for(int j = 0; j < c; j++) {
        cin>>mat[i][j];
      }
    }
    int max = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < c; j++) {
        if(mat[i][j] == 'A') {
          int t = dfs(i, j, h, c, dp, mat);
          if (t > max) max = t;
        }
      }
    }
    // for(int i = 0; i < h; i++) {
    //   for(int j = 0; j < c; j++) 
    //     cout<<mat[i][j]<<" ";
    //     cout<<endl;
    // }
    // dfs(0, 0, h, c, dp, mat);
    // for(int i = 0; i < h; i++) {
    //   for(int j = 0; j < c; j++) 
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    ctr ++;
    cout<<"Case "<<ctr<<": "<<max<<endl;

  }
	return 0;
}