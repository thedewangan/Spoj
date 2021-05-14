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
    vector < vector <ll> > mat;
    vector < vector <ll> > val;
    queue < pair <int,int> > q;
    vector< pair <int,int> > neighbours;
    pair <int,int> p;

    mat.resize(r);
    val.resize(r);

    for(int i = 0; i < r; i++) {
      mat[i].resize(c);
      val[i].resize(c);
      for(int j = 0; j < c; j++) {
        cin>>mat[i][j];
        val[i][j] = 999999;
      }
    }
    int m, n;
    ll T;
    cin>>m>>n>>T;
    m--; n--;

    // for(int i = 0; i < r; i++) {
    //   for(int j = 0; j < c; j++) {
    //     cout<<mat[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    val[0][0] = mat[0][0];
    q.push(make_pair(0, 0));
    while(q.size()) {
      p = q.front();
      q.pop();
      neighbours = getNeighbours(p.first, p.second, r, c);
      int u, v;
      for(int i = 0; i < neighbours.size(); i++) { 
        u = neighbours[i].first;
        v = neighbours[i].second;
        if(val[u][v] == -1) val[u][v] = val[p.first][p.second] + mat[u][v];
        // using -1 instead of infinity
        else if(val[p.first][p.second] + mat[u][v] < val[u][v]) {
          val[u][v] = val[p.first][p.second] + mat[u][v];
          q.push(make_pair(u, v));
        }
      }
    }
    // cout<<"\n\n";
    // for(int i = 0; i < r; i++) {
    //   for(int j = 0; j < c; j++) {
    //     cout<<mat[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    if(val[m][n] <= T) {
      cout<<"YES\n"<<T-val[m][n]<<endl;
    } else cout<<"NO\n";

  }
	return 0;
}