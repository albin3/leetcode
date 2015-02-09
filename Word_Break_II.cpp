#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> result;
    void findWord(string s, stack<string> stk, int d, vector<vector<int> > v) {
      if (d==0) {
        // print stk;
        string str = stk.top();
        stk.pop();
        while(!stk.empty()) {
          str += " ";
          str += stk.top();
          stk.pop();
        }
        result.push_back(str);
      } else {
        int i;
        for (i=0; i<v[d].size(); i++) {
          int next = v[d][i];
          stk.push(s.substr(next, d-next));
          findWord(s, stk, next, v);
          stk.pop();
        }
      }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      vector<string> vs;
      vector<vector<int> > v(s.length()+1);
      int i=0,j=1;
      for (i=0; i<s.length(); i++) {
        for (j=i+1; j<=s.length(); j++) {
          string sub = s.substr(i, j-i);
          if (dict.find(sub)!=dict.end()) {
            v[j].push_back(i);
          }
        }
      }
      for (i=0; i<v.size(); i++) {
        cout<<"line "<<i<<" :";
        for (j=0; j<v[i].size(); j++) {
          cout<<v[i][j]<<",";
        }
        cout<<endl;
      }
      stack<string> stks;
      findWord(s, stks, s.length(), v);
      return result;
    }
};

int main() {
  // string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  // unordered_set<string> uset = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  // string s="catsanddog";
  // unordered_set<string> uset = {"cat", "cats", "and", "sand", "dog"};
  // string s="a";
  // unordered_set<string> uset = {"a"};
  string s="bb";
  unordered_set<string> uset = {"a", "b", "bbb", "bbbb"};
  vector<string> vs = (new Solution)->wordBreak(s, uset);
  int i=0;
  cout<<vs.size();
   while(i<vs.size()) {
     cout<<"v: "<<vs[i++]<<endl;
  }
}

/*
 1. 直接动态规划，用栈保存已有状态，不断向前规划,
 2. [存在的问题]
*/
/*
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      vector<string> vs;
      queue<stack<int> > qs;
      stack<int> si;
      si.push(0);
      int i=0,j=0;
      while (!si.empty()) {
        for(; j<=s.length(); j++) {
          if (dict.find(s.substr(si.top(), j-si.top()))!=dict.end()) {
            si.push(j);
            if (j==s.length()) {
              qs.push(si);
              si.pop();
              cout<<si.size()<<":"<<si.top()<<endl;
            }
            break;
          }
        }
        if (j>=s.length()) {
          if (si.size()==2) 
            si=si;
          j = si.top()+1;
          si.pop();
        } else {
          j = si.top()+1;
        }
        // if (si.size()<=1) break;
      }
      while(!qs.empty()){
        stack<int> stmp = qs.front();
        qs.pop();
        stmp.pop();
        string tmp = s;
        while(stmp.size()>1) {
          tmp.insert(stmp.top(), " ");
          stmp.pop();
        }
        vs.push_back(tmp);
      }
      return vs;
    }
};
*/
