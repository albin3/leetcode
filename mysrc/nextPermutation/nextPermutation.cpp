// Source : https://leetcode.com/problems/next-permutation/
// Author : Albin Zeng
// Date : 2015-04-19

/***************************************************************************************************************************
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. 
 *
 * Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 **************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:
    // 题意： 找到下一个排列， 比如：123的下一个排列是132; 
    //                               132的下一个拍类是213;
    // 思路： 将整个排列当作一个数，当数要加一时，
    //        只要找到合适的位置进位就行了, 而该进位的地方是
    //        倒序排列的所有位，是需要进位的地方，然后找到前
    //        一个数,将其替换为后面倒序排列中比它大一个等级的
    //        数，将后面的数正序排列。完成进位。
    void nextPermutation(vector<int> &num) {
      
      int len = num.size();
      if (len < 2) return;
      
      int pos = len-1;
      while (pos>0) {
        if (num[pos] <= num[pos-1]) {
          pos = pos - 1;
        } else {
          break;
        }
      }

      // 整个数组是倒序的，只需要把它正过来
      if (pos == 0) {
        reverse(num.begin(), num.end());
        return ;
      }

      // 找到进位后的数,并跟前一位数交换,再将后面的数倒回来
      int old = num[pos-1];
      int next = len-1;
      while (num[next] <= num[pos-1]) {
        next--;
      }
      int tmp = num[pos-1];
      num[pos-1] = num[next];
      num[next] = tmp;
      reverse(num.begin()+pos, num.end());

      return ;
    }
};

int main() {

  vector<int> v;
  v.push_back(1);
  v.push_back(5);
  v.push_back(1);

  (new Solution)->nextPermutation(v);
  for (int i=0; i<v.size(); i++) {
    cout<<v[i]<<endl;
  }

  return 0;
}
