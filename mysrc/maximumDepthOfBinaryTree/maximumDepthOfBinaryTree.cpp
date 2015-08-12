// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Albin Zeng
// Date : 2015-08-12

//返回二叉树的高

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        stack<TreeNode*> s;
        stack<int> vs;
        int depth = 1;
        s.push(root);
        vs.push(0);
        
        while (!s.empty()) {
            if (s.size() > depth) {
                depth = s.size();
            }
            if (vs.top() == 2) {
                s.pop();
                vs.pop();
                continue;
            } else if (vs.top() == 1) {
                if (s.top()->right != NULL) {
                    s.push(s.top()->right);
                    vs.top()++;
                    vs.push(0);
                } else {
                    vs.top()++;
                }
                continue;
            } else {
                if (s.top()->left != NULL) {
                    s.push(s.top()->left);
                    vs.top()++;
                    vs.push(0);
                } else {
                    vs.top()++;
                }
                continue;
            }
        }
        return depth;
    }
};
