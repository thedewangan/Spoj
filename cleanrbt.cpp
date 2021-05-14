#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits.h>

#define ll long long 

using namespace std;

typedef pair <int, int> iPair;

int qualifies(char ch, int &mask) {
  if (ch == 'x') return 0;
  else if (ch >= '0' && ch <= '9') {
    int i = ch - '0';
    mask = mask|(1<<i);
  }
  return 1;
}

vector < pair<iPair, int> > getNeighbours(int i, int j, int mask, int h, int c, vector< vector<char> > &mat){ 
  vector< pair <iPair,int> > neighbours;
  for(int x=-1; x <=1; x++) {
    for(int y =-1; y<=1; y++) {
      int u = i+x;
      int v = j+y;
      if((u==i || v==j) && !(u==i && v==j) && u >= 0 && u < h && v>=0 && v < c) {
        int newMask = mask; 
        int q = qualifies(mat[u][v], newMask);
        //cout<<"u:"<<u<<" v:"<<v<<" - "<<q<<"        ";
        if(q) {
          iPair p = make_pair(u, v);
          neighbours.push_back(make_pair(p, newMask));
        }
      }
    }
  }
  //cout<<"Neighbour size "<<neighbours.size()<<endl;
  return neighbours;
}

int main()
{	
  while(1) {
    int r, c;
    cin>>c>>r;
    if(r==0 && c==0) break;

    vector < vector <char> > mat;
    vector < vector < vector <int> > > cost;
    queue < pair <iPair, int> > q;
    mat.resize(r);
    cost.resize(r);

    int a, b, numDirty = 0;

    for(int i = 0; i < r; i++) {
      mat[i].resize(c);
      cost[i].resize(c);
      for(int j = 0; j < c; j++) {
        cin>>mat[i][j];
        if(mat[i][j] == 'o') {
          a = i;
          b = j;
          //cout<<"A B "<<a<<b<<endl;
        } else if (mat[i][j] == '*') {
          mat[i][j] = '0' + numDirty;
          numDirty++;
        }
        cost[i][j].resize(1024, INT_MAX);
      }
      //cout<<endl;
    }
    //cout<<endl;
    iPair p = make_pair(a, b);
    q.push(make_pair(p, 0));
    cost[a][b][0] = 0;

    int flag = 0;
    int steps = INT_MAX;

    while(q.size()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int mask = q.front().second;
      q.pop();
      if(mask == pow(2, numDirty) - 1) {
        steps = min(steps, cost[x][y][mask]);
        continue;
      }
      //cout<<"\n("<<x<<","<<y<<","<<mask<<")\t: ";
  
      vector < pair<iPair, int> >neighbours = getNeighbours(x, y, mask, r, c, mat);
      for(int i = 0; i < neighbours.size(); i++) {
        int u = neighbours[i].first.first;
        int v = neighbours[i].first.second;
        int m = neighbours[i].second;
        if(1 + cost[x][y][mask] < cost[u][v][m]) {
          //cout<<"("<<u<<","<<v<<","<<m<<")  ";
          cost[u][v][m] = 1 + cost[x][y][mask];
          q.push(neighbours[i]);
        }
      }
    }
    if(steps == INT_MAX) cout<<-1<<endl;
    else cout<<steps<<endl;

  }
	return 0;
}