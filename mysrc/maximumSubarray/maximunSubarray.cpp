// Source : https://leetcode.com/problems/maximum-subarray/
// Author: Albin Zeng.
// Date: 2015-06-23

/**********************************************************************************************************
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 *
 *********************************************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if (nums.size() < 1) return 0;
        
        int max = -(int)(((unsigned int)-1)/2)-1;
        int currentsum = 0;
        
        for (int i=0; i<nums.size(); i++) {
            currentsum += nums[i];
            max = max > currentsum ? max : currentsum;
            currentsum = currentsum > 0 ? currentsum : 0;
        }
        
        return max;
    }
};
