// Source : https://leetcode.com/problems/unique-binary-search-trees/
// Author : Albin Zeng
// Date : 2015-08-12

//输入n，返回包含n个元素，然后符合二叉搜索树的总个数

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n < 2) return 1;
        if (n == 2) return 2;

        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        v.push_back(2);

        for (int i=3; i<=n; i++) {
            int cur = 0;
            for (int j=0; j<i; j++) {
                cur += v[j] * v[(i-1)-j];
            }
            v.push_back(cur);
        }

        return v[n];
    }
};

int main() {
  cout<<(new Solution)->numTrees(3)<<endl;
}
