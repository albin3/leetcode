// Source : https://leetcode.com/problems/3sum/
// Author : Albin Zeng
// Date : 2015-04-12
// Reference : http://www.programcreek.com/2012/12/leetcode-3sum/

/***************************************************************************************************
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *
 * The solution set must not contain duplicate triplets.
 *
 * For example, given array S = {-1 0 1 2 -1 -4},
 * 
 * A solution set is:
 * (-1, 0,  1)
 * (-1, -1, 2)
 *
 *************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // like TwoSum , use a target and search target in map.
    // two pointers search.
    vector<vector<int> > threeSum(vector<int> &num) {

      vector<vector<int> > result;

      // sort by algorithm
      sort(num.begin(), num.end());


      for (int i=0; i<num.size(); i++) {

        if (i-1>=0 && num[i-1]==num[i]) {
          continue;
        }

        int target = -num[i];

        int l=i+1;
        int r=num.size()-1;
        while (l<r) {
          if (num[l]+num[r] == target) {
            vector<int> v;
            v.push_back(num[i]);
            v.push_back(num[l]);
            v.push_back(num[r]);
            result.push_back(v);

            // important: skip the duplication
            while (l<r && num[l] == num[l+1]) l++;
            while (l<r && num[r] == num[r-1]) r--;

            l++;
            r--;
          } else if (num[l]+num[r] < target) {
            l++;
          } else if (num[l]+num[r] > target) {
            r--;
          }
        }

      }

      return result;
    }
};

int main() {
  vector<int> v;
  v.push_back(0);
  v.push_back(-1);
  v.push_back(1);
  v.push_back(-1);
  v.push_back(2);
  v.push_back(4);
  vector<vector<int> > result = (new Solution)->threeSum(v);
  cout<<result.size()<<endl;
  for (int i=0; i<result.size(); i++) {
    for (int j=0; j<result[i].size(); j++) {
      cout<<"#"<<result[i][j];
    }
    cout<<endl;
  }
}

