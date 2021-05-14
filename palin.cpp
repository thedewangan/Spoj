#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

template <class T>
int numDigits(T number) {
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int findDigit(ll num, ll digit, ll numDigits) {
  int temp = (num/pow(10, numDigits - digit));
  return  temp % 10;
}
bool isPalindrome(int num, int numDigits) {
  for(int i = 1; i <= numDigits/2; i++) {
    if ( (num % int(pow(10, i)))/int(pow(10, i - 1)) != int(num/pow(10, numDigits - i)) % 10)
      return false;
  }
  return true;
}
int reverse(int num) {
  int d = numDigits(num);
  int newNum = 0;
  int cur;
  for(int i = 1; i <= d; i++) {
    cur = num % int(pow(10, i));
    cur = cur / pow(10, i - 1);
    newNum = newNum + cur * pow(10, d - i);
  }
  return newNum;
}
int createPalindrome(int firstHalf, int secondHalf, int d) {
  firstHalf++;
  int nl = numDigits(firstHalf);
  int partialFirstHalf = firstHalf/pow(10, nl - int(d/2));
  int reversePartialFirstHalf = reverse(partialFirstHalf);
  int pal = firstHalf * pow(10, d/2) + reversePartialFirstHalf;
  return pal;
}

int main()
{
  ll T;
	cin>>T;
  while(T--)
  {
    int num;
    int mid;
    int pl;
    cin >> num;
    int d = numDigits(num);
    if (d == 1) {
      if(num == 9) cout<<11<<"\n";
      else cout<<num+1<<"\n";
      continue;
    }

    if (d%2 == 0 ) mid = d/2;
    else mid = d/2 + 1;

    int firstHalf = num/pow(10, int(d/2));
    int partialFirstHalf = (d%2 == 0) ? firstHalf : firstHalf/10;
    int secondHalf = num % int(pow(10, int(d/2)));

    int reversePartialFirstHalf = reverse(partialFirstHalf);
    if (reversePartialFirstHalf > secondHalf) {
      int pal = firstHalf * pow(10, d/2) + reversePartialFirstHalf;
      cout<<pal<<"\n";
    }
    else {
      int pal = createPalindrome(firstHalf, secondHalf, d);
      cout<<pal<<"\n";
    }
	}

	return 0;
}