#include<sstream>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
      string c = "1";
      while(n>1) {
        stack<char> s;
        int i=c.length();
        while(i>0) {
          s.push(c[i-1]);
          i--;
        }
        c = "";
        while(!s.empty()) {
          char num = s.top();
          int count = 1;
          s.pop();
          while(!s.empty() && num==s.top()) {
            count++;
            s.pop();
          }
          stringstream ss;
          ss<<count;
          c = c+ss.str();
          c = c+num;
        }
        n--;
      }
      return c;
    }
    void display() {
    }
};

int main(int argc, char* argv[]) {
  int c;
  cout<<(new Solution)->countAndSay(1)<<endl;
  cout<<(new Solution)->countAndSay(2)<<endl;
  cout<<(new Solution)->countAndSay(3)<<endl;
  cout<<(new Solution)->countAndSay(4)<<endl;
  cout<<(new Solution)->countAndSay(5)<<endl;
  cout<<(new Solution)->countAndSay(6)<<endl;
  cout<<(new Solution)->countAndSay(7)<<endl;
  cout<<(new Solution)->countAndSay(8)<<endl;
  cout<<(new Solution)->countAndSay(9)<<endl;
  cout<<(new Solution)->countAndSay(10)<<endl;
  cout<<(new Solution)->countAndSay(11)<<endl;
  cout<<(new Solution)->countAndSay(12)<<endl;
  cin>>c;
}
