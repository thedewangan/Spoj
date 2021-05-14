#include <iostream>
#include <vector>

#define ll long long 
/**
FINDING LONGEST PATH IN A TREE
*/
using namespace std;

vector< vector<int> > G;


struct data {
  int depth;
  int farNode;
};
struct data dfs(int node, vector <int> &visited) {
  // cout<<"Node "<< node + 1<<endl;
  struct data a, b;
  visited[node] = 1;
  int maxDepth = 0;
  int farNode = node + 1; // natural number for current node
  for(int j = 0; j < G[node].size(); j++) {
    if (!visited[G[node][j] - 1]) {
      a = dfs(G[node][j] - 1, visited);
      int furtherDepth = a.depth;
      if(furtherDepth + 1 > maxDepth) {
         maxDepth = 1 + furtherDepth;
         farNode = a.farNode;
      }
    }
  }
  b.depth = maxDepth;
  b.farNode = farNode;
  return b;
}

int main()
{	
  int N, M;
  cin>>N;
  M = N - 1;
  G.resize(N);
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
  vector <int> visited;
  visited.resize(N, 0);
  int farNode = 1;
  struct data ans, ans2;
  ans = dfs(0, visited);
  for(int i = 0; i < N; i++) visited[i] = 0;
  ans2 = dfs(ans.farNode - 1, visited);
  cout<<ans2.depth;
    

	return 0;
}