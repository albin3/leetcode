#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    map<int,vector<int> > m;
    int i=0;
    for (; i<numbers.size(); i++) {
      vector<int> v_tmp = m[numbers[i]];
      v_tmp.push_back(i+1);
      m[numbers[i]] = v_tmp;
    }

    map<int, vector<int> >::iterator m_it = m.begin();
    vector<int> v;
    for (; m_it!=m.end(); m_it++) {
      v.push_back(m_it->first);
    }
    int s = v.size();

    m_it = m.begin();
    for (i=0; m_it!=m.end(); m_it++,i++) {
      if (m_it->second.size()>1 && m_it->first*2 == target) {
        vector<int> v_rtn;
        v_rtn.push_back(m_it->second[0]);
        v_rtn.push_back(m_it->second[1]);
        return v_rtn;
      }
      int low=i,high=s;
      int p_num = m_it->first;
      int p_ind = (low+high)/2;
      while (low != high) {
        if (p_num+v[p_ind] == target) {
          vector<int> v_rtn;
          if(m[p_num][0]<m[v[p_ind]][0]) {
            v_rtn.push_back(m[p_num][0]);
            v_rtn.push_back(m[v[p_ind]][0]);
          } else {
            v_rtn.push_back(m[v[p_ind]][0]);
            v_rtn.push_back(m[p_num][0]);
          }
          return v_rtn;
        }
        if (p_num+v[p_ind] > target) {
          high = p_ind;
          p_ind = (low+high)/2;
        }
        if (p_num+v[p_ind] < target) {
          low = p_ind+1;
          p_ind = (low+high)/2;
        }
      }
    }
  }
};

int main(int argc, char* argv[]) {
  map<int, vector<int> > mm;
  cout<<(mm[2].size())<<endl;
  vector<int> v;
  v.push_back(0);
  v.push_back(4);
  v.push_back(3);
  v.push_back(0);
  vector<int> v_rst = (new Solution)->twoSum(v,7);
  for (int i=0; i<v_rst.size(); i++) {
    cout<<i<<":"<<v_rst[i]<<endl;
  }
}
