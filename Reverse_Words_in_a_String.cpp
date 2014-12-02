#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
      int j=0;
      while(j<s.length() && s[j] == ' ') j++;
      if (j==s.length()) {
        s="";
        return;
      }
      int i=0;
      int l = s.length();
      stack<string> s_s;
      for(; i<l; i++) {
        string tmp = "";
        while(i<l && s[i] == ' ') {
          tmp += " ";
          i++;
        }

        tmp = "";
        while(i<l && s[i] != ' ') {
          tmp += s.substr(i,1);
          i++;
        }
        s_s.push(tmp);
        if(i==l-1 && s[l-1] != ' ') {
          s_s.push(s.substr(l-1,1));
        }
      }

      s = "";
      while (!s_s.empty() && s_s.top() == "") s_s.pop();
      s+=s_s.top();
      s_s.pop();
      while(!s_s.empty()) {
        s+=" ";
        s = s+s_s.top();
        s_s.pop();
      }
    }
};

int main() {
  string s = "a ";
  (new Solution)->reverseWords(s);
  cout<<"#"<<s<<"#"<<endl;
  cin>>s;
}
