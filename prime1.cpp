#include <iostream>
#include <math.h>
#define ll long long 

using namespace std;

int main()
{	
	long long N,x,y;
	cin>>N;
	while(N)
	{
		cin>>x>>y;
		for(ll i=x; i<=y; i++)
		{
			int flag =0;
			for(ll j=2; j<=sqrt(i); j++)
			{
				//cout<< i%j<<"\n";
				if(i%j==0) { 
					//cout<< i%j<<"\n";
					flag = 1;
					break;
				}
			}
			if(flag==0 and i!=1) cout<<i<<"\n";
		}
		cout<<"\n";
		N--;
	}
	return 0;
}