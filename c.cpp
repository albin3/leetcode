#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
      int w = board.size();
      if(w<2) return;
      int h = board[0].size();

      int i=0,j=0;
      vector<vector<int> > mstate;
      for (;i<w;i++) {
        vector<int> vi;
        for (;j<h;j++) {
          vi.push_back(0);
        }
        mstate.push_back(vi);
      }
      queue<pair<int,int> > qp;

      for (int j=0; j<board[0].size(); j++) {
        if (board[0][j] == '0' && mstate[0][j]==0) {
          mstate[0][j]=1;
          qp.push(make_pair(0,j));
          while(!qp.empty()) {
            pair<int,int> tmp = qp.front();
            qp.pop();
            int x = tmp.first;
            int y = tmp.second;
            if (x-1>=0 && board[x-1][y]=='0' && mstate[x-1][y]==0) {
              qp.push(make_pair(x-1,y));
              mstate[x-1][y]=1;
            }
            if (x+1<w && board[x+1][y]=='0' && mstate[x+1][y]==0) {
              qp.push(make_pair(x+1,y));
              mstate[x+1][y]=1;
            }
            if (y-1>=0 && board[x][y-1]=='0' && mstate[x][y-1]==0) {
              qp.push(make_pair(x,y-1));
              mstate[x][y-1]=1;
            }
            if (y+1<h && board[x][y+1]=='0' && mstate[x][y+1]==0) {
              qp.push(make_pair(x,y+1));
              mstate[x][y+1]=1;
            }
          }
        }
      }
      for (int j=0; j<board[0].size(); j++) {
        if (board[w-1][j] == '0' && mstate[w-1][j]==0) {
          mstate[w-1][j]=1;
          qp.push(make_pair(w-1,j));
          while(!qp.empty()) {
            pair<int,int> tmp = qp.front();
            qp.pop();
            int x = tmp.first;
            int y = tmp.second;
            if (x-1>=0 && board[x-1][y]=='0' && mstate[x-1][y]==0) {
              qp.push(make_pair(x-1,y));
              mstate[x-1][y]=1;
            }
            if (x+1<w && board[x+1][y]=='0' && mstate[x+1][y]==0) {
              qp.push(make_pair(x+1,y));
              mstate[x+1][y]=1;
            }
            if (y-1>=0 && board[x][y-1]=='0' && mstate[x][y-1]==0) {
              qp.push(make_pair(x,y-1));
              mstate[x][y-1]=1;
            }
            if (y+1<h && board[x][y+1]=='0' && mstate[x][y+1]==0) {
              qp.push(make_pair(x,y+1));
              mstate[x][y+1]=1;
            }
          }
        }
      }

      for (int i=0; i<board.size(); i++) {
        if (board[i][0] == '0' && mstate[i][0]==0) {
          mstate[i][0]=1;
          qp.push(make_pair(i,0));
          while(!qp.empty()) {
            pair<int,int> tmp = qp.front();
            qp.pop();
            int x = tmp.first;
            int y = tmp.second;
            if (x-1>=0 && board[x-1][y]=='0' && mstate[x-1][y]==0) {
              qp.push(make_pair(x-1,y));
              mstate[x-1][y]=1;
            }
            if (x+1<w && board[x+1][y]=='0' && mstate[x+1][y]==0) {
              qp.push(make_pair(x+1,y));
              mstate[x+1][y]=1;
            }
            if (y-1>=0 && board[x][y-1]=='0' && mstate[x][y-1]==0) {
              qp.push(make_pair(x,y-1));
              mstate[x][y-1]=1;
            }
            if (y+1<h && board[x][y+1]=='0' && mstate[x][y+1]==0) {
              qp.push(make_pair(x,y+1));
              mstate[x][y+1]=1;
            }
          }
        }
      }
      for (int i=0; i<board.size(); i++) {
        if (board[i][h-1] == '0' && mstate[i][h-1]==0) {
          mstate[i][h-1]=1;
          qp.push(make_pair(i,h-1));
          while(!qp.empty()) {
            pair<int,int> tmp = qp.front();
            qp.pop();
            int x = tmp.first;
            int y = tmp.second;
            if (x-1>=0 && board[x-1][y]=='0' && mstate[x-1][y]==0) {
              qp.push(make_pair(x-1,y));
              mstate[x-1][y]=1;
            }
            if (x+1<w && board[x+1][y]=='0' && mstate[x+1][y]==0) {
              qp.push(make_pair(x+1,y));
              mstate[x+1][y]=1;
            }
            if (y-1>=0 && board[x][y-1]=='0' && mstate[x][y-1]==0) {
              qp.push(make_pair(x,y-1));
              mstate[x][y-1]=1;
            }
            if (y+1<h && board[x][y+1]=='0' && mstate[x][y+1]==0) {
              qp.push(make_pair(x,y+1));
              mstate[x][y+1]=1;
            }
          }
        }
      }
      i=0,j=0;
      for (i=0; i<w; i++) {
        for(j=0; j<h; j++) {
          if(mstate[i][j]==0) {
            board[i][j] = 'X';
          }
        }
      }
      return;
    }
};

int main() {
  vector<vector<char> > board;
  vector<char> vtmp;
  /*
  vtmp.push_back('X');vtmp.push_back('X');vtmp.push_back('X');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  vtmp.push_back('X');vtmp.push_back('0');vtmp.push_back('0');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  vtmp.push_back('0');vtmp.push_back('X');vtmp.push_back('0');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  vtmp.push_back('0');vtmp.push_back('0');vtmp.push_back('X');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  */
  /*
  vtmp.push_back('X');vtmp.push_back('X');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  vtmp.push_back('X');vtmp.push_back('0');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  vtmp.push_back('X');vtmp.push_back('X');vtmp.push_back('X');
  board.push_back(vtmp);
  vtmp.clear();
  */
  vtmp.push_back('0');vtmp.push_back('0');
  board.push_back(vtmp);
  vtmp.clear();
  vtmp.push_back('0');vtmp.push_back('0');
  board.push_back(vtmp);
  vtmp.clear();

  int w = board.size();
  int h = board[0].size();
  int i,j;
  for (i=0; i<w; i++) {
    for(j=0; j<h; j++) {
      cout<<board[i][j]<<",";
    }
    cout<<endl;
  }
  (new Solution)->solve(board);
  for (i=0; i<w; i++) {
    for(j=0; j<h; j++) {
      cout<<board[i][j]<<",";
    }
    cout<<endl;
  }
}
