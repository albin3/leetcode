// Source: https://leetcode.com/problems/anagrams/
// Author: Albin Zeng
// Date: 2015-06-11

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string, string> m;
        vector<string> result;
        for (int i=0; i<strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (m.find(sorted) != m.end()) {
                if (m[sorted] != "USED") {
                    result.push_back(m[sorted]);
                    m[sorted] = "USED";
                }
                result.push_back(strs[i]);
            } else {
                m[sorted] = strs[i];
            }
        }
        return result;
    }
};
