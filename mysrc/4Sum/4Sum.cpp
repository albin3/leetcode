// Source : https://leetcode.com/problems/4sum/
// Author : Albin Zeng
// Date : 2015-04-12

/******************************************************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *
 * The solution set must not contain duplicate quadruplets.
 *
 *    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *    A solution set is:
 *    (-1,  0, 0, 1)
 *    (-2, -1, 1, 2)
 *    (-2,  0, 0, 2)
 *
 ****************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
      vector<vector<int> > result;
      if (num.size()<4) return result;

      sort(num.begin(), num.end());

      for (int i=0; i<num.size(); i++) {
        for (int j=i+1; j<num.size()-2; j++) {

          int t = target-num[i]-num[j];

          int l = j+1;
          int r = num.size()-1;
          while (l<r) {
            if (num[l]+num[r] == t) {
              vector<int> tmp;
              tmp.push_back(num[i]);
              tmp.push_back(num[j]);
              tmp.push_back(num[l]);
              tmp.push_back(num[r]);
              result.push_back(tmp);
              // skip dulplication.
              while (l<r && num[l]==num[l+1]) l++;
              while (l<r && num[r]==num[r-1]) r--;
              l++;
              r--;
            } else if (l<r && num[l]+num[r] > t) {
              r--;
            } else if (l<r && num[l]+num[r] < t) {
              l++;
            }
          }
          while (j+1<num.size() && num[j] == num[j+1]) j++;
        }
        while (i+1<num.size() && num[i] == num[i+1]) i++;
      }

      return result;
    }
};

int main() {
  vector<int> input;
  input.push_back(1);
  input.push_back(0);
  input.push_back(-1);
  input.push_back(0);
  input.push_back(-2);
  input.push_back(2);
  vector<vector<int> > v = (new Solution)->fourSum(input,0);

  for (int i=0; i<v.size(); i++) {
    for (int j=0; j<v[i].size(); j++) {
      cout<<"#"<<v[i][j];
    }
    cout<<endl;
  }
}
