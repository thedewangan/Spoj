#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


#define ll long long 

using namespace std;

string str = "ALLIZZWELL";

vector < pair<int, int> > getNeighbours(int i, int j, int h, int c, int index,vector< vector<int> > &visited, vector< vector<char> > &mat){ 
  vector< pair <int,int> > neighbours;
  for(int x=-1; x <=1; x++) {
    for(int y =-1; y<=1; y++) {
      int u = i+x;
      int v = j+y;
      if((u!=i || v!=j) && u >= 0 && u < h && v>=0 && v < c) {
        if (mat[u][v] == str[index] && visited[u][v] == 0){
          //cout<<u<<" "<<v<<endl;
          neighbours.push_back(make_pair(u, v));
        }
      }
    }
  }
  //cout<<"Neighbour size "<<neighbours.size()<<endl;
  return neighbours;
}
int dfs(int i, int j, int h, int c, int index, vector< vector<int> > &visited, vector< vector<char> > &mat) {
  //cout<<"In dfs\t"<<i<<" "<<j<<" . Index "<<index<<endl;
  visited[i][j] = 1;
  if (index == 9) {
    //cout<<"AT THE END\n";
    return 1;
  }
  vector < pair<int, int> > v;
  v = getNeighbours(i, j, h, c, index + 1, visited, mat);
  //cout<<v.size()<<endl;

  for(int x = 0; x < v.size(); x++) {
    int p = dfs(v[x].first, v[x].second, h, c, index + 1, visited, mat);
    if (p == 1) return 1;
  }
  visited[i][j] = 0;
  return 0;
} 

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    // width is c
    int h, c, ans = 0;
    cin>>h>>c;
    vector< vector<char> > mat;
    vector< vector<int> > visited;
    mat.resize(h);
    visited.resize(h);
  
    for(int i = 0; i < h; i++) {
      mat[i].resize(c);
      visited[i].resize(c, 0);
      for(int j = 0; j < c; j++) {
        cin>>mat[i][j];
      }
    }
    if(h*c < 10) {cout<<"NO\n"; continue;}

    for(int i = 0; i < h; i++) {
      for(int j = 0; j < c; j++) {
        if(mat[i][j] == 'A') {
          int index = 0;
          int t = dfs(i, j, h, c, index, visited, mat);
          if (t == 1) {ans  = 1; break;}
        }
      }
      if(ans) break;
    }
    // for(int i = 0; i < h; i++) {
    //   for(int j = 0; j < c; j++) 
    //     cout<<mat[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<dfs(0, 0, h, c, 0, visited, mat)<<endl;
    // for(int i = 0; i < h; i++) {
    //   for(int j = 0; j < c; j++) 
    //     cout<<visited[i][j]<<" ";
    //   cout<<endl;
    // }

    if(ans) cout<<"YES\n";
    else cout<<"NO\n";

  }
	return 0;
}