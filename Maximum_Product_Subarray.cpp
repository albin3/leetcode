#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
      if (n==1) return A[0];

      int i=0;
      int l,r;
      int flag = 0;
      vector<pair<int, int> > v_p;
      while(i<n) {
        l=i;
        while(i<n && A[i]!=0) {
          i++;
        }
        if (i<n && A[i]==0) flag=1;
        r=i;
        v_p.push_back(make_pair(l,r));
        i++;
      }
      int max = A[0];
      vector<pair<int, int> >::iterator it = v_p.begin();
      for (; it!=v_p.end(); it++) {
        pair<int,int> p_tmp = *it;
        int pro=A[p_tmp.first];
        int j=p_tmp.first+1;
        for (; j<p_tmp.second; j++) pro*=A[j];
        int tmp = pro;
        int lmax = pro;
        for(j=p_tmp.first; j<p_tmp.second-1; j++) {
          tmp/=A[j];
          if (tmp > lmax) {
            lmax = tmp;
          }
        }
        tmp = pro;
        int rmax = pro;
        for(j=p_tmp.second-1; j>p_tmp.first; j--) {
          tmp/=A[j];
          if (tmp > rmax) {
            rmax = tmp;
          }
        }
        if (lmax > max) {
          max = lmax;
        }
        if (rmax > max) {
          max = rmax;
        }
      }
      if (flag) max = max>0 ? max:0;
      return max;
    }
};

int main() {
  int p[4] = {-2,0,-1,0};
  cout<<(new Solution)->maxProduct(p,4);
  cin>>p[0];
}
