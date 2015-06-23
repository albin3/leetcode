// Source: https://leetcode.com/problems/merge-intervals/
// Author: Albin Zeng.
// Date: 2015-06-23

/************************************************************************
 * 
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 ************************************************************************/
// 排序+处理
// sort的排序为: function(int a, int b) { return a<b };
// 处理时判断后者是否被包含

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if (intervals.size() < 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), judge);
        
        vector<Interval> result;
        result.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++) {
            if (result[result.size()-1].end >= intervals[i].start) {
                result[result.size()-1].end = intervals[i].end > result[result.size()-1].end ? intervals[i].end : result[result.size()-1].end;
            } else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
    
    static bool judge(Interval a, Interval b) {
        if (a.start < b.start) {
            return true;
        } else if (a.start == b.start) {
            return a.end < b.end;
        }
        return false;
    }
};
