#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits.h>
#include <functional>

#define ll long long 
using namespace std;

typedef pair <int, int> iPair;

//prims

int main() {
  int V, E;
  cin>>V>>E;
  vector <int> key, processed;
  vector < vector<int> > mat, weight;

  key.resize(V, INT_MAX);
  mat.resize(V);
  weight.resize(V);
  processed.resize(V, 0);

  for(int i = 0; i < V; i++) {
    weight[i].resize(V, INT_MAX);
  }
  for(int i = 0; i < E; i++) {
    int u, v, w;
    cin>>u>>v>>w;
    weight[u-1][v-1] = w;
    weight[v-1][u-1] = w;
    mat[u-1].push_back(v-1);
    mat[v-1].push_back(u-1);
  }
  int s, d;
  s = 0;
  priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  key[0] = 0;
  pq.push(make_pair(0, 0));
  ll sum = 0;

  while(pq.size()) {
    int u = pq.top().second;
    pq.pop();
    if(processed[u]) continue;
    sum += key[u];
    for(int i = 0; i < mat[u].size(); i++) {
      int v = mat[u][i];
      if(weight[u][v] < key[v]) {
        //cout<<v+1<<" ";
        key[v] = weight[u][v];
        pq.push(make_pair(key[v], v));
      }
    }
    //cout<<endl;
    processed[u] = 1;
  }
  cout<<sum;
  // for(int u = 0; u < V; u++) {
  //   for(int i = 0; i < mat[u].size(); i++) {
  //     int v = mat[u][i];
  //     if(weight[u][v] < INT_MAX) cout<<u+1<<" "<<v+1<<" "<<weight[u][v]<<endl;
  //   }
  // }
}