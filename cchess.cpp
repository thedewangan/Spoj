#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <utility>

#define ll long long 

using namespace std;

typedef pair <int, int> iPair;

vector < pair<int, int> > getNeighbours(int i, int j, int h, int c){ 
  vector< pair <int,int> > neighbours;
  int a[16] = {-2,-1, -2,1, 2,-1, 2,1,   -1,-2, -1,2, 1,-2, 1,2};
  for(int ctr=0; ctr<16; ctr+=2) {
    int u = i + a[ctr];
    int v = j + a[ctr+1];
    if(u >= 0 && u < h && v>=0 && v < c) {
      neighbours.push_back(make_pair(u, v));
    }
  }
  //cout<<"Neighbour size "<<neighbours.size()<<endl;
  return neighbours;
}

int main()
{	
  while(1) {
    int a, b, c, d;
    cin>>a;
    if(cin.eof()) break;
    cin>>b>>c>>d;
    if(a == c && b == d) {
      cout<<0<<endl;
      continue;
    }

    iPair p;
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    vector < vector <int> > cost, visited;
    cost.resize(8);
    visited.resize(8);

    for(int i = 0; i < 8; i++) {
      cost[i].resize(8, 99999);
      visited[i].resize(8, 0);
    }

    cost[a][b] = 0;
    int node = 8*a + b;
    pq.push(make_pair(a, node));

    while(pq.size()) {
      p = pq.top();
      pq.pop();
      int x = p.second/8;
      int y = p.second%8;
      if(visited[x][y]) {
        if(x == c && y == d) break;
        else continue;
      }
      else visited[x][y] = 1;

      vector <iPair> neighbours = getNeighbours(x, y, 8, 8);
      for(int i = 0; i < neighbours.size(); i++) {
        int u = neighbours[i].first;
        int v = neighbours[i].second;
        int edgeCost = x*u + y*v;
        if(!visited[u][v] && cost[x][y] + edgeCost < cost[u][v]) {
          cost[u][v] = cost[x][y] + edgeCost;
          pq.push(make_pair(cost[u][v], 8*u + v));
        }  
      }
    }
    if(cost[c][d] < 99999) cout<<cost[c][d]<<endl;
    else cout<<-1<<endl;
  }
	return 0;
}