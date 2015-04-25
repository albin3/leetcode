// Source : https://leetcode.com/problems/combination-sum/
// Author : Albin Zeng
// Date : 2015-04-25

/********************************************************************************
 * 
 * Given a set of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
 * (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 * 
 ********************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

      sort(candidates.begin(), candidates.end());

      vector<vector<int> > result;

      vector<int> p;
      solveHelper(result, candidates, 0, p, target);

      return result;
    }

    void solveHelper(vector<vector<int> > &r, vector<int> &c, int pos, vector<int> &p, int target) {

      for (int i=pos; i<c.size(); i++) {
          vector<int> tmp = p;
          tmp.push_back(c[i]);

        if (c[i] < target) {
          vector<int> tmp = p;
          tmp.push_back(c[i]);
          solveHelper(r, c, i, tmp, target-c[i]);
          continue;

        } else if (c[i] == target) {
          r.push_back(tmp);
          return;

        } else {
          return;
        }

      }

    }
};

int main() {

  vector<int> c;
  c.push_back(2);
  c.push_back(3);
  c.push_back(6);
  c.push_back(7);
  vector<vector<int> > r = (new Solution)->combinationSum(c, 7);

  for (int i=0; i<r.size(); i++) {
    for (int j=0; j<r[i].size(); j++) {
      cout<<r[i][j]<<",";
    }
    cout<<endl;
  }
}
