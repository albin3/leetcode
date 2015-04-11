// Source : https://leetcode.com/problems/two-sum/
// Author : Albin. Zeng
// Date   : 2015-04-10

/********************************************************************************************************
 *
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
 * are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * 
 ********************************************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    map<int, int> m;
    vector<int> result;
    for (int i=0; i<numbers.size(); i++) {
      int num = numbers[i];
      if (m.find(num) != m.end()) {
        result.push_back(m[num]+1);
        result.push_back(i+1);
        return result;
      } else {
        m[target-numbers[i]] = i;
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  map<int, vector<int> > mm;
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
