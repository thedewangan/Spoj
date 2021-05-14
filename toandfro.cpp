#include <iostream>
#include <string>
#include <vector>

#define ll long long 

using namespace std;

int main()
{	

  while(1) {
    vector< vector<char> > mat;
    string str;
    int r, c;
    cin>>c;
    if(!c) break;
    cin>>str;
    r = str.length()/c;
    mat.resize(r);
    int k = 0;
    for(int i = 0; i < r; i++) {
      mat[i].resize(c);
      if(i%2 == 0) {
        for(int j = 0; j < c; j++) {
          mat[i][j] = str[k];
          k++;
        }
      } else {
        for(int j = c - 1; j >= 0; j--) {
          mat[i][j] = str[k];
          k++;
        }
      }
    }

    for(int j = 0; j < c; j++) {
      for(int i = 0; i < r; i++) {
        cout<<mat[i][j];
      }
    }
    cout<<endl;
  }
	return 0;
}