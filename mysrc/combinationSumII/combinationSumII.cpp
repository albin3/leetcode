// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : Albin Zeng
// Date : 2015-04-25

/*********************************************************************************************************
 * 
 * Given a collection of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 * 
 ********************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {

      vector<vector<int> > result;

      sort(num.begin(), num.end());

      vector<int> p;
      solveHelper(result, num, 0, p, target);

      return result;
    }

    // 注意重复数的问题
    void solveHelper(vector<vector<int> > &r, vector<int> &n, int pos, vector<int> p, int target)
    {
      if (target == 0) {
        r.push_back(p);
        return;
      } else if (target<0) {
        return;
      }
      for (int i=pos; i<n.size(); i++) {
        if (i!=pos && n[i-1]==n[i]) {
          continue;
        }
        if (target>=n[i]) {
          p.push_back(n[i]);
          solveHelper(r, n, i+1, p, target-n[i]);
          p.pop_back();
        }
      }
    }
};

int main() {

  int nums[55] = {14,6 ,25,9 ,30,20,33,34,28,30,
                16,12,31,9 ,9 ,12,34,16,25,32,
                8 ,7 ,30,12,33,20,21,29,24,17,
                27,34,11,17,30,6 ,32,21,27,17,
                16,8 ,24,12,12,28,11,33,10,32,
                22,13,34,18,12};
  vector<int> c(nums, nums+55);
  vector<vector<int> > r = (new Solution)->combinationSum2(c, 27);

  for (int i=0; i<r.size(); i++) {
    for (int j=0; j<r[i].size(); j++) {
      cout<<r[i][j]<<",";
    }
    cout<<endl;
  }
  
}
