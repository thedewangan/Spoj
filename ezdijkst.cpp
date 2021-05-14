#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits.h>
#include <functional>

#define ll long long 
using namespace std;

typedef pair <int, int> iPair;

/* DIJKSTRA */
int main() {

  int T;
  cin>>T;
  while(T--) {
    int V, E;
    cin>>V>>E;
    vector <int> dist, processed;
    vector < vector<int> > mat, weight;

    dist.resize(V, INT_MAX);
    mat.resize(V);
    weight.resize(V);
    processed.resize(V, 0);

    for(int i = 0; i < V; i++) {
      weight[i].resize(V, 0);
    }
    for(int i = 0; i < E; i++) {
      int u, v, w;
      cin>>u>>v>>w;
      weight[u-1][v-1] = w;
      mat[u-1].push_back(v-1);
      //mat[v-1].push_back(u-1);
    }
    int s, d;
    cin>>s>>d;
    // study functional header file, greater etc
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    dist[s-1] = 0;
    pq.push(make_pair(dist[s-1], s-1));
    while(pq.size()) {
      int u = pq.top().second;
      pq.pop();
      if(processed[u]) continue;
      for(int i = 0; i < mat[u].size(); i++) {
        int v = mat[u][i];
        if(dist[u] + weight[u][v] < dist[v]) {
          dist[v] = dist[u] + weight[u][v];
          pq.push(make_pair(dist[v], v));
        }
      }
      processed[u] = 1;
    }
    if(dist[d-1] < INT_MAX) cout<<dist[d-1]<<endl;
    else cout<<"NO";
  }
}