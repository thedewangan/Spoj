#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define ll long long 

using namespace std;



vector < pair<int, int> > getNeighbours(int i, int j, int h, int c){ 
  vector< pair <int,int> > neighbours;
  for(int x=-1; x <=1; x++) {
    for(int y =-1; y<=1; y++) {
      int u = i+x;
      int v = j+y;
      if((u==i || v==j) && !(u==i && v==j) && u >= 0 && u < h && v>=0 && v < c) {
        neighbours.push_back(make_pair(u, v));
      }
    }
  }
  //cout<<"Neighbour size "<<neighbours.size()<<endl;
  return neighbours;
}

int main()
{	
  int T;
  cin>>T;
  while(T--) {
    int r, c;
    cin>>r>>c;
    vector < vector <int> > mat;
    queue < pair <int,int> > q;
    vector< pair <int,int> > neighbours;
    pair <int,int> p;

    mat.resize(r);
    char ch;
    for(int i = 0; i < r; i++) {
      mat[i].resize(c);
      for(int j = 0; j < c; j++) {
        cin>>ch;
        mat[i][j] = ch - 48;
        if(mat[i][j] == 1) {
          mat[i][j] = 0;
          q.push(make_pair(i, j));
        } else {
          mat[i][j] = 999999;
        }
      }
    }
    // for(int i = 0; i < r; i++) {
    //   for(int j = 0; j < c; j++) {
    //     cout<<mat[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }

    while(q.size()) {
      p = q.front();
      q.pop();
      neighbours = getNeighbours(p.first, p.second, r, c);
      int u, v;
      for(int i = 0; i < neighbours.size(); i++) { 
        u = neighbours[i].first;
        v = neighbours[i].second;
        if(mat[p.first][p.second] + 1 < mat[u][v]) {
          mat[u][v] = mat[p.first][p.second] + 1;
          q.push(make_pair(u, v));
        }
      }
    }
    //cout<<"\n\n";
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cout<<mat[i][j]<<" ";
      }
      cout<<"\n";
    }

  }
	return 0;
}