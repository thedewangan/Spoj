#include <iostream>
#include <string>

#define ll long long 

using namespace std;

struct TrieNode {
  TrieNode * children[26];
  bool isEndOfWord;
  TrieNode() {
    for(int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isEndOfWord = false;
  }
};

void insert(TrieNode *root, string s) {
  TrieNode *cur = root, *temp;

  for(int i=0; i<s.size(); i++) {
    int ch = s[i] - 'a';
    if(cur->children[ch]) {
      cur = cur->children[ch];
    } else {
      temp = new TrieNode();
      cur->children[ch] = temp;
      cur = temp;
    }
  }
  cur->isEndOfWord = true;
}

bool find(TrieNode *root, string s) {
  TrieNode *cur = root, *temp;

  for(int i=0; i<s.size(); i++) {
    int ch = s[i] - 'a';
    if(cur->children[ch]) {
      cur = cur->children[ch];
    } else {
      return false;
    }
  }
  return cur->isEndOfWord;
}

int main()
{	

  TrieNode *root = new TrieNode();
  insert(root, "hero");
  insert(root, "ant");
  insert(root, "zebra");
  insert(root, "antman");
  insert(root, "he");

  cout<<find(root, "hro")<<endl;
  cout<<find(root, "ant")<<endl;
  cout<<find(root, "zebra")<<endl;
  cout<<find(root, "antman")<<endl;
  cout<<find(root, "heroine")<<endl;

  return 0; 
}