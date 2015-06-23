// Source : https://leetcode.com/problems/spiral-matrix/
// Author : Albin Zeng.
// Date : 2015-06-23

/*****************************************************************************************
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 * [ 1, 2, 3 ],
 * [ 4, 5, 6 ],
 * [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 *
 *****************************************************************************************/

// 0ms 完美解
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        
        int m = matrix.size();
        if (m < 1) return result;
        int n = matrix[0].size();
        
        int mid_m = m/2;
        int mid_n = n/2;
        int i = 0;
        while (i<mid_m && i<mid_n) {
            // 上横
            for (int j=i; j<n-i-1; j++) {
                result.push_back(matrix[i][j]);
            }
            // 右竖
            for (int j=i; j<m-i-1; j++) {
                result.push_back(matrix[j][n-i-1]);
            }
            // 下横
            for (int j=n-i-1; j>i; j--) {
                result.push_back(matrix[m-i-1][j]);
            }
            // 左竖
            for (int j=m-i-1; j>i; j--) {
                result.push_back(matrix[j][i]);
            }
            i++;
        }
        if (m<n && m%2==1) {
            for (int j=i; j<=n-i-1; j++) {
                result.push_back(matrix[i][j]);
            }
        }
        if (n<=m && n%2==1) {
            for (int j=i; j<=m-i-1; j++) {
                result.push_back(matrix[j][i]);
            }
        }
        
        return result;
    }
};
