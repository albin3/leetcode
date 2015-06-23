// Source: https://leetcode.com/submissions/detail/30932793/
// Author: Albin Zeng.
// Date: 2015-06-23

/****************************************************************************
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 ****************************************************************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int currentMax = 0;
        int len = nums.size();
        if (len<1) return false;
        
        for (int i=0; i<len; i++) {
            int current = i+nums[i];
            currentMax = current > currentMax ? current : currentMax;
            if (currentMax >= len-1) return true;
            if (currentMax == i) return false;
        }
        
        return true;
    }
};
