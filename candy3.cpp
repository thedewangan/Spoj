#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ll T, N, x, sum ;

	cin>>T;

	while(T--)
	{
		sum = 0;
		cin>>N;
		ll n = N;
		while(n--)
		{
			cin>>x;
			sum+=x;
			sum = sum % N;
			
		}
		if(!(sum%N)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}