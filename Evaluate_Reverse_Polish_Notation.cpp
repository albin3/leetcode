#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator it=tokens.begin();
        stack<int> s;
        for(; it!=tokens.end(); it++) {
          string str = *it;
          if (str == "+") {
            int i1 = s.top();
            s.pop();
            int i2 = s.top();
            s.pop();
            s.push(i2+i1);
          } else if (str == "-") {
            int i1 = s.top();
            s.pop();
            int i2 = s.top();
            s.pop();
            s.push(i2-i1);
          } else if(str == "*") {
            int i1 = s.top();
            s.pop();
            int i2 = s.top();
            s.pop();
            s.push(i2*i1);
          } else if (str == "/") {
            int i1 = s.top();
            s.pop();
            int i2 = s.top();
            s.pop();
            s.push(i2/i1);
          } else {
            istringstream buffer(str);
            int value;
            buffer>>value;
            s.push(value);
          }
        }
        return s.top();
    }
};
int main() {
  vector<string> vs;
  vs.push_back(string("4"));
  vs.push_back(string("13"));
  vs.push_back(string("5"));
  vs.push_back(string("/"));
  vs.push_back(string("+"));
  cout<<(new Solution)->evalRPN(vs)<<endl;
  int n;
  cin>>n;
}
