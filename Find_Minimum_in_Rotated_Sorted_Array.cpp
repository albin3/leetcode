#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
      int i;
      int s = num.size();
      for(i=0; i<num.size(); i++) {
        if(i == num.size()-1) {
          return num[0];
        }
        if (num[i]>num[i+1]) 
          break;
      }
      return num[i+1];
    }
};

int main(int argc, char* argv[]) {
  int q[2] = {2,1};
  vector<int> v(q,q+2);
  cout<<(new Solution)->findMin(v);
  cin>>q[0];
}
