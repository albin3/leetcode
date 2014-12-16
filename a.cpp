#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      vector<string> v;
      stack<int> st;
      st.push(0);
      while (!st.empty()) {
        string str = s.substr();
      }
      return v;
    }
};

int main() {
  string s="catsanddog";
  unordered_set<string> uset = {"cat", "cats", "and", "sand", "dog"};
  vector<string> v = (new Solution)->wordBreak(s, uset);
  int i=0;
  while(i<v.size()) {
    cout<<"v: "<<v[i++]<<endl;
  }
}
