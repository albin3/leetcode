// Source : https://leetcode.com/problems/longest-palindromic-substring/
// Author : Albin Zeng
// Date   : 2015-04-11
// References : http://www.programcreek.com/2013/12/leetcode-solution-of-longest-palindromic-substring-java/

/******************************************************************
 *
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 *
 ******************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    // O(n^3) normal solution.
    string longestPalindrome(string s) {
      
      int len = s.length();
      int max_sub_len = -1;
      string max_subs;

      if (len<1) {
        max_subs = "";
      } else {
        max_subs = s.substr(0,1);
      }

      string sub_str;
      for (int i=0; i<len; i++) {
        for (int j=2; j<=len-i; j++) {
          sub_str = s.substr(i,j);
          if (isPalindromic(sub_str) && j-i>max_sub_len) {
            max_sub_len = j-i;
            max_subs = sub_str;
          }
        }
      }
      return max_subs;
    }

    bool isPalindromic(string str) {

      int len = str.length();

      for (int i=0; i<len/2; i++) {
        if (str[i]!=str[len-1-i]) {
          return false;
        }
      }

      return true;
    }

    // O(n^2) Solution
    string longestPalindrome1(string s) {

      int len = s.length();
      int max = 0;
      string max_str;

      for (int i=0; i<len; i++) {
        int l;
        int r;
        
        // 奇数位palindromic string
        l=i; 
        r=i;
        while (l>=0&&r<len) {
          if (s[l]==s[r]) {
            l = l-1;
            r = r+1;
          } else {
            break;
          }
        }
        if (r-l-1>max) {
          max = r-l-1;
          max_str = s.substr(l+1, r-l-1);
        }

        // 偶数位palindromic string
        if (i==s.length()-1)
          continue;

        l=i; 
        r=i+1;
        while (l>=0&&r<len) {
          if (s[l]==s[r]) {
            l = l-1;
            r = r+1;
          } else {
            break;
          }
        }
        if (r-l-1>max) {
          max = r-l-1;
          max_str = s.substr(l+1, r-l-1);
        }
      }

      return max_str;
    }
};

int main(int argc, char* argv[]) {
  cout<<(new Solution)->longestPalindrome1("esbtziaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq")<<endl;
  return 0;
}
