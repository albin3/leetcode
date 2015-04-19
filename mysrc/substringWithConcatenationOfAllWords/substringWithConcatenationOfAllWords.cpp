// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : Albin Zeng
// Date : 2015-04-15

/********************************************************************************************************
 *
 * You are given a string, S, and a list of words, L, that are all of the same length. 
 *
 * Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly 
 * once and without any intervening characters.
 *
 * For example, given:
 *
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 ********************************************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {

      vector<int> result;

      if (L.size()<1) return result;

      int len = L[0].size();

      map<string, int> map1,map2;
      for (int i=0; i<L.size(); i++) {
        if (map1.find(L[i]) == map1.end()) {
          map1[L[i]] = 1;
        } else {
          map1[L[i]] = map1[L[i]]+1;
        }
      }

      for (int i=0; i<=(int)S.size()-(int)L.size()*len; i++) {
              map2.clear();
              for (int j=0; j<L.size(); j++) {
                      if (map1.find(S.substr(i+j*len,len)) != map1.end()) {
                              map2[S.substr(i+j*len,len)]++;
                      } else {
                              break;
                      }
              }
              bool flag = true;
              for (int j=0; j<L.size(); j++) {
                      if (map1[L[j]] != map2[L[j]]) {
                              flag = false;
                              break;
                      }
              }
              if (flag) {
                      result.push_back(i);
              }
      }

      return result;
    }
};

int main() {
        vector<int> v;

        string S = "a";
        vector<string> L;
        L.push_back("a");
        v = (new Solution)->findSubstring(S, L);

        for (int i=0; i<v.size(); i++) {
                cout<<v[i]<<endl;
        }
}
