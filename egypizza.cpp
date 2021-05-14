#include <iostream>
#include <math.h>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{	
  int N;
  cin>>N;

  float n, d;
  char ch;
  float h = 0;
  float t = 0;
  float q = 0;
  float pizza = 0;
  float extraHalves = 0;
  float extraQuarters = 0;
  float reqd = 0;


  for(int i = 0; i < N; i++) {
    cin>>n;
    cin>>ch;
    cin>>d;
    float val = n/d;
    //cout<<val<<endl;
    if (val == 0.5) h++;
    else if(val == 0.75) t++;
    else q++;
  }
  //cout<<h<<" "<<t<<" "<<q<<endl;
  pizza = ceil(h*0.5);
  extraHalves = pizza - (h*0.5);
  pizza += t;
  extraQuarters += t;
  extraQuarters += extraHalves*2;
  if(q > extraQuarters) reqd = ceil((q - extraQuarters)/4);

  pizza += reqd;

  cout<<pizza + 1<<endl;
	return 0;
}