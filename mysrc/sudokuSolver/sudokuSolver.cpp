// Source : https://leetcode.com/problems/sudoku-solver/
// Author : Albin Zeng
// Date : 2015-04-21

/*************************************************************************
 * 
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 * 
 *************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:

    void solveSudoku(vector<vector<char> > &board) {

      // 直接进行深度优先遍历
      vector<vector<char> > m = board;

      int s = board.size();

      int idx = 0;
      while (idx<s*s) {

        if (m[idx/s][idx%s] != '.') { idx++; continue;}

        int next = findNext(board, idx/s, idx%s);
        if (next<0) {
          board[idx/s][idx%s] = '.';
          idx--;
          while (idx>0 && m[idx/s][idx%s] != '.') idx--;
          continue;
        } else {
          board[idx/s][idx%s] = '1'+next;
          idx++;
        }
      }
      
      return;
    }

    char findNext(vector<vector<char> > &board, int i, int j) {

      int store = 0;
      int now = -1;
      int next = -1;

      int s = board.size();

      if (board[i][j] == '.') {
        now = -1;
      } else {
        now = board[i][j] - '1';
      }

      for (int k=0; k<s; k++) {
        int num = board[i][k] - '1';
        if (num<0) continue;
        store = store | 1<<num;
      }
      for (int k=0; k<s; k++) {
        int num = board[k][j] - '1';
        if (num<0) continue;
        store = store | 1<<num;
      }
      for (int k=0; k<9; k++) {
        int num = board[i/3*3+k/3][j/3*3+k%3] - '1';
        if (num<0) continue;
        store = store | 1<<num;
      }

      for (int i=now+1; i<9; i++) {
        if (((store>>i)%2) == 0) return i;
      }
      cout<<now<<":"<<store<<endl;
      return -1;
    }

    bool isValid(vector<vector<char> > &board, int i, int j) {

      int s = board.size();
      if (!(i>=0&&i<s&&j>=0&&j<s)) return false;

      int store = 0;
      for (int k=0; k<s; k++) {
        int num = board[i][k] - '1';
        if (num<0) continue;
        if ((store & 1<<num) > 0) return false;
        store = store | 1<<num;
      }

      store = 0;
      for (int k=0; k<s; k++) {
        int num = board[k][j] - '1';
        if (num<0) continue;
        if ((store & 1<<num) > 0) return false;
        store = store | 1<<num;
      }

      store = 0;
      for (int k=0; k<9; k++) {
        int num = board[i/3*3+k/3][j/3*3+k%3] - '1';
        if (num<0) continue;
        if ((store & 1<<num) > 0) return false;
        store = store | 1<<num;
      }
      return true;
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
  (new Solution)->solveSudoku(v);
  cout<<"<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
  for (int i=0; i<v.size(); i++) {
    for (int j=0; j<v.size(); j++) {
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}
