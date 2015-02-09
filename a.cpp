#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int n = nRows+nRows/2;
        int j,k,i = 0;
        int row;
        int size = s.size();
        string r(size);
        for(; i<size; i++) {
          int id = i%n;
          if (id<nRows) {
            row = id;
          } else {
            row = (id-nRows)*2;
          };
          
        }
        return r;
    }
};
