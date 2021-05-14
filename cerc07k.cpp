#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits.h>

#define ll long long 

using namespace std;

typedef pair <int, int> iPair;

int convert(char ch) {
  switch (ch) {
    case 'b': 
    case 'B': return 0;
    case 'y': 
    case 'Y': return 1;
    case 'r': 
    case 'R': return 2;
    case 'g': 
    case 'G': return 3;
  }
  return -1;
}

int qualifies(char ch, int &mask) {
  if(ch == '.' || ch == 'X' || ch == '*') return 1;
  else if (ch == '#') return 0;
  else if (ch > 90) {
    int i = convert(ch);
    mask = mask|(1<<i);
    return 1;
  }
  else {
    int i = convert(ch);
    return mask&(1<<i);
  }
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
    cin>>r>>c;
    if(r==0 && c==0) break;

    vector < vector <char> > mat;
    vector < vector < vector <int> > > cost;
    queue < pair <iPair, int> > q;
    mat.resize(r);
    cost.resize(r);

    int a, b;

    for(int i = 0; i < r; i++) {
      mat[i].resize(c);
      cost[i].resize(c);
      for(int j = 0; j < c; j++) {
        cin>>mat[i][j];
        if(mat[i][j] == '*') {
          a = i;
          b = j;
          //cout<<"A B "<<a<<b<<endl;
        }
        cost[i][j].resize(16, INT_MAX);
      }
      //cout<<endl;
    }
    //cout<<endl;
    iPair p = make_pair(a, b);
    q.push(make_pair(p, 0));
    cost[a][b][0] = 0;
    int flag = 0;
    while(q.size()) {
      int x = q.front().first.first;
      int y = q.front().first.second;
      int mask = q.front().second;
      q.pop();
      if(mat[x][y] == 'X') {
        //cout<<"\n"<<cost[x][y][mask]<<"mask "<<mask<<endl;
        cout<<"Escape possible in "<<cost[x][y][mask]<<" steps."<<endl;
        flag = 1;
        break;
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
    if(!flag) cout<<"The poor student is trapped!"<<endl;

  }
	return 0;
}