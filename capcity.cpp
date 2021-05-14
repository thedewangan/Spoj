#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long 
// scc strongly connected components
using namespace std;

int ctr = 0;

void dfs(int node, vector <int> &visited, vector< vector<int> > &G) {
  // cout<<"Node "<< node + 1<<endl;
  visited[node] = 1;
  ctr++;
  for(int j = 0; j < G[node].size(); j++) {
    if (!visited[G[node][j]]) {
      dfs(G[node][j], visited, G);
    }
  }
  return;
}

int main()
{	
  vector< vector<int> > G, G2;
  int N, M;
  cin>>N>>M;
  G.resize(N);
  G2.resize(N);
  int u,v;
  for(int i = 0; i < M; i++) {
    scanf("%d%d", &u, &v);
    // cout<<u<<" "<<v<<"\n";
    G[u-1].push_back(v-1);
    G2[v-1].push_back(u-1);
  }

  // for(int i = 0; i < N; i++) {
  //   cout<<i<<" : ";
  //   for(int j = 0; j < G2[i].size(); j++) {
  //     cout<<G2[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  vector <int> visited, candidate;
  visited.resize(N, 0);

  int lastNode = -1;
  for(int i = 0; i < N; i++) {
    if(!visited[i]) {
      dfs(i, visited, G2);
      lastNode = i;
    }
  }
  
  //for(int i = 0; i < N; i++) visited[i] = 0;
  fill(visited.begin(), visited.end(), 0);
  ctr = 0;
  dfs(lastNode, visited, G);
  cout<<ctr<<endl;
  for(int i = 0; i < N; i++) {
    if(visited[i]) {
      cout<<i+1<<" ";
      //candidate.push_back(i+1);
    }
  }
  //sort(candidate.begin(), candidate.end());
  //cout<<candidate.size()<<endl;
  //for(int i = 0; i < candidate.size(); i++) cout<<candidate[i]<<" ";
	return 0;
}