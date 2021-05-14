#include <iostream>
#include <string>

#define ll long long

using namespace std;

int main()
{
	string str;

	while(1)
	{
		cin>>str;
		if(str=="0") break;

		ll dp[str.length()];

		dp[0] = 1;
		if(str.length()>1)
			dp[1] = (stoi(str.substr(0,2)) <=26 )and str[1] != '0'? 2:1;
		//cout<<dp[1]<<endl;

		for(int i=2; i<str.length(); ++i)
		{
			//cout<<stoi(str.substr(i-1,2))<<endl;


			if((stoi(str.substr(i-1,2))) <=26 and str[i-1]!='0')
			{
				if(str[i]=='0')	dp[i] = dp[i-2];
				else  dp[i] = dp[i-2] + dp[i-1];
			}
			else
			{
				dp[i] = dp[i-1];
				// if(str[i]!='0')	dp[i] = dp[i-1];
				// else 
				// { 
				// 	dp[str.length()-1] = 0;
				// 	break;
				// }
			} 
		}		
		cout<<dp[str.length()-1]<<endl;
	}
	return 0;
}