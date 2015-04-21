// Source : https://leetcode.com/problems/valid-sudoku/
// Author : Albin Zeng
// Date : 2015-04-21

/*********************************************************************************************************************
 * 
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 *
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 * 
 ********************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // TODO: 别人用内存换时间的算法值得学习
    bool isValidSudoku(vector<vector<char> > &board) {

      int len = board.size();

      if (len<1) return true;

      if (len%3 != 0) return false;

      bool result = true;

      for (int i=0; i<len; i++) {

        // 横向
        int store = 0;
        for (int j=0; j<len; j++) {
          if (board[i][j] != '.') {
            int num = board[i][j]-'1';
            if ((1<<num & store) > 0) {
              return false;
            } else {
              store += 1<<num;
            }
          }
        }

        store = 0;
        for (int j=0; j<len; j++) {
          if (board[j][i] != '.') {
            int num = board[j][i]-'1';
            if ((1<<num & store) > 0) {
              return false;
            } else {
              store += 1<<num;
            }
          }
        }
      }

      for (int i=0; i<len/3; i++) {
        for (int j=0; j<len/3; j++) {
          int store = 0;
          for (int x=0; x<3; x++) {
            for(int y=0; y<3; y++) {

              if (board[i*3+x][j*3+y] == '.') {
                continue;
              }

              int num = board[i*3+x][j*3+y]-'1';
              if ((1<<num & store) > 0) {
                return false;
              } else {
                store += 1<<num;
              }

            }
          }
        }
      }

      return result;
    }
};

int main() {
  vector<vector<char> > v;
  char row1[9] = {'.', '.', '5', '.', '.', '.', '.', '.', '6'};
  char row2[9] = {'.', '.', '.', '.', '1', '4', '.', '.', '.'};
  char row3[9] = {'.', '.', '.', '.', '.', '9', '2', '.', '.'};
  char row4[9] = {'5', '.', '.', '.', '.', '2', '.', '.', '.'};
  char row5[9] = {'.', '.', '.', '.', '.', '.', '.', '3', '.'};
  char row6[9] = {'.', '.', '.', '5', '4', '.', '.', '.', '.'};
  char row7[9] = {'3', '.', '.', '.', '.', '.', '4', '2', '.'};
  char row8[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
  char row9[9] = {'.', '.', '.', '2', '7', '.', '6', '.', '.'};
  vector<char> tmp1(row1, row1+9); v.push_back(tmp1);
  vector<char> tmp2(row2, row1+9); v.push_back(tmp2);
  vector<char> tmp3(row3, row1+9); v.push_back(tmp3);
  vector<char> tmp4(row4, row1+9); v.push_back(tmp4);
  vector<char> tmp5(row5, row1+9); v.push_back(tmp5);
  vector<char> tmp6(row6, row1+9); v.push_back(tmp6);
  vector<char> tmp7(row7, row1+9); v.push_back(tmp7);
  vector<char> tmp8(row8, row1+9); v.push_back(tmp8);
  vector<char> tmp9(row9, row1+9); v.push_back(tmp9);
  for (int i=0; i<v.size(); i++) {
    for (int j=0; j<v.size(); j++) {
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<(new Solution)->isValidSudoku(v)<<endl;
}
