// Source: htitps://leetcode.com/problems/permutations/
// Author: Albin Zeng
// Date: 2015-05-18

/***********************************************************************
 *
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 **********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
      
      vector<vector<int> > result;

      vector<int> tmp;
      sort(nums.begin(), nums.end());
      helper(result, tmp, nums);

      return result;
    }
    void helper(vector<vector<int> > &r,vector<int> rst, vector<int> remain) {

      if (remain.size() == 0) {
        r.push_back(rst);
        return;
      }

      //注意这里的it
      for (vector<int>::iterator it=remain.begin(); it!=remain.end(); it++) {
        int item = *it;
        rst.push_back(item);
        remain.erase(it);
        helper(r, rst, remain);
        rst.pop_back();
        remain.insert(it, item);
      }
    }
};

int main() {
  ;
}
