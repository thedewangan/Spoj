#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;

string addToString(string str1, int a) {
  string head = "0";
  str1 =  head + str1;
  string res =  str1;
  int l = res.length();
  int carry = 0;
  int add = a;
  for(int i = l-1; i >= 0; i--) {
    if (i != l-1) add = 0;
    int t = str1[i] - '0';
    res[i] = ((t + add + carry) % 10) + '0';
    carry = (t + add + carry) / 10;
  }
  if (res[0] == '0') res = res.substr(1, l - 1);
  return res;
}

int firstIsGreater(string str1, string str2) {
  // cout<<"FIG";
  // return 0;
  if (str1.length() > str2.length()) return 1;
  else if (str1.length() < str2.length()) return -1;
  else {
    // cout<<"FIG@";
    int val = str1.compare(str2);
    // cout<<"VAL"<<val<<endl;
    return val;
  }
}

string createPalindrome(string firstHalf, string secondHalf, int lengthOfSecondHalf) {
  firstHalf = addToString(firstHalf, 1);
  string newSecondHalf = firstHalf.substr(0, lengthOfSecondHalf);
  reverse(newSecondHalf.begin(), newSecondHalf.end());
  return firstHalf + newSecondHalf;
}
int main()
{
  ll T;
  cin>>T;
  while(T--)
  {
    string num;
    int mid;
    int pl;
    cin >> num;
    int d = num.length();
    if (d == 1) {
      if(num == "9") cout<<"11"<<"\n";
      else cout<<to_string(stoi(num) + 1)<<"\n";
      continue;
    }

    if (d%2 == 0 ) mid = d/2;
    else mid = d/2 + 1;
    string firstHalf = num.substr(0, mid);
    string partialFirstHalf = (d%2 == 0) ? firstHalf : firstHalf.substr(0, mid - 1);
    string secondHalf = num.substr(mid , d/2);
    string reversePartialFirstHalf = partialFirstHalf;
    reverse(reversePartialFirstHalf.begin(), reversePartialFirstHalf.end());

    // cout<<firstHalf<<" "<<partialFirstHalf<<" "<<secondHalf<<" "<<reversePartialFirstHalf<<"\n";
    if (firstIsGreater(reversePartialFirstHalf, secondHalf) > 0) {
      string pal = firstHalf + reversePartialFirstHalf;
      cout<<pal<<"\n";
    }
    else {
      string pal = createPalindrome(firstHalf, secondHalf, d/2);
      cout<<pal<<"\n";
    }
	}

	return 0;
}