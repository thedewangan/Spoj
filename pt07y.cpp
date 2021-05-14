#include <iostream>
#include <vector>

#define ll long long 
/**
DETECTING IF A GRAPH IS A TREE
*/
using namespace std;

int N, M;
vector< vector<int> > G;
vector <int> visited;

int dfs(int node, int parent) {
  // cout<<"Node "<< node + 1<<endl;
  if (visited[node]) return -1;
  else visited[node] = 1;
  for(int j = 0; j < G[node].size(); j++) {
    if (G[node][j] != parent) {
      int ret = dfs(G[node][j] - 1, node + 1);
      if (ret == -1) return -1;
    }
  }
  return 0;
}

int main()
{	
  cin>>N>>M;
  G.resize(N);
  visited.resize(N, 0);
  int u,v;
  for(int i = 0; i < M; i++) {
    cin>>u>>v;
    // cout<<u<<" "<<v<<"\n";
    G[u-1].push_back(v);
    G[v-1].push_back(u);
  }

  // for(int i = 0; i < M; i++) {
  //   cout<<i+1<<" : ";
  //   for(int j = 0; j < G[i].size(); j++) {
  //     cout<<G[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }

  int a = dfs(0, -1);
    
  for(int i = 0; i < N; i++) {
    //cout<<visited[i];
    if(visited[i] == 0) 
    {
      cout<<"NO\n";
      return 0;
    }
  }
  if (a == 0) cout<<"YES\n";
  else cout<<"NO\n";
	return 0;
}