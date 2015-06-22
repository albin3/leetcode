// Source: https://leetcode.com/problems/n-queens/
// Author: Albin Zeng
// Date: 2015-06-22

/**************************************
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 * [".Q..",  // Solution 1
 *  "...Q",
 *  "Q...",
 *  "..Q."],
 *
 * ["..Q.",  // Solution 2
 *  "Q...",
 *  "...Q",
 *  ".Q.."]
 * ]
 *
 *************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {

public:

    vector<vector<string> > solveNQueens(int n) {
        
      vector<vector<string> > result;
      vector<pair<int, int> > p;
      solveHelper(p, 0, n, n, result);
      return result;
    }

    void solveHelper(vector<pair<int, int> >& p, int idx, int remain, int n, vector<vector<string> >& result) {

        bool yes =  judge(p);

        if (remain == 0 && yes) {

            result.push_back(genMap(p, n));

        } else if (yes) {

            int start = 0;
            if (!p.empty()) {
              start = p[p.size()-1].first*n+n;
              if (p[0].first>0) return;
            } 
            
            for (int i=start; i<start+n; i++) {
              pair<int, int> newP(i/n, i%n);
              p.push_back(newP);
              solveHelper(p, i, remain-1, n, result);
              p.pop_back();
            }

        }

    }

    vector<string> genMap(vector<pair<int, int> > p, int n) {

      string oneLine(n, '.');
      vector<string> result(n, oneLine);

      for (int i=0; i<p.size(); i++) {
        result[p[i].first][p[i].second] = 'Q';
      }

      return result;
    }

    bool judge(vector<pair<int, int> > p) {

      for (int i=0; i<(int)p.size()-1; i++) {

        pair<int, int> p1 = p[i];
        pair<int, int> p2 = p[p.size()-1];

        if (p1.first == p2.first || p1.second == p2.second || 
          (p2.second-p1.second)*1.0/(p2.first-p1.first) == 1 ||
          (p2.second-p1.second)*1.0/(p2.first-p1.first) == -1)  
            return false;
      }
      return true;

    }

};

int main() {
  vector<vector<string> > r = (new Solution)->solveNQueens(9);
  cout<<"rsize()"<<r.size()<<endl;
  for (int i=0; i<r.size(); i++) {
    cout<<"No "<<i<<":"<<endl;
    for (int j=0; j<r[i].size(); j++) {
      cout<<r[i][j]<<endl;
    }
  }
  return 0;
}
