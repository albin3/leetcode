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

    int totalNQueens(int n) {
        
      int result;
      vector<int> p;
      vector<int> remain;
      for (int i=0; i<n; i++) {
        remain.push_back(i);
      }
      solveHelper(p, remain, result);
      return result;
    }

    void solveHelper(vector<int> p, vector<int> remain, int &n) {

        bool yes =  judge(p);

        if (remain.size() == 0 && yes) {

          n++;

        } else if (yes) {

          for (int i=0; i<remain.size(); i++) {
            int item = remain[i];
            p.push_back(item);
            remain.erase(remain.begin()+i);
            solveHelper(p, remain, n);
            p.pop_back();
            remain.insert(remain.begin()+i, item);
          }

        }

    }

    bool judge(vector<int> p) {

      for (int i=0; i<(int)p.size()-1; i++) {

        int x1 = i, y1 = p[i];
        int x2 = p.size()-1, y2 = p[p.size()-1];

        if (x1 == x2 || y1 == y2 || (y1-y2)*1.0/(x1-x2) == 1  || (y1-y2)*1.0/(x1-x2) == -1) {
          return false;
        }

      }
      return true;

    }

};

int main() {
  int n = (new Solution)->totalNQueens(9);
  cout<<n<<endl;
  return 0;
}
