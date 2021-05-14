#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <utility>

#define ll long long 

using namespace std;

typedef pair <int, int> iPair;
typedef struct point {
  int x, y;
} point;


int main()
{	
  int N;
  cin>>N;
  vector <point> points;
  for(int i = 0; i < N; i++) {
    point p;
    cin>>p.x>>p.y;
    points.push_back(p);
  }

	return 0;
}