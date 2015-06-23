// Source: https://leetcode.com/problems/length-of-last-word/
// Author: Albin Zeng.
// Date: 2015-06-24

/**********************************************************************
 * 
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 * 
 **********************************************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int maxlen = s.size()-1;
        while (maxlen >= 0 && s[maxlen] == ' ') maxlen--;
        for (int i=0; i<=maxlen; i++) {
            if (s[i] == ' ') len = 0;
            else len++;
        }
        return len;
    }
};
