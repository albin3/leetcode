// Source : https://leetcode.com/problems/same-tree/
// Author : Albin Zeng
// Date : 2015-08-12

//判断两个二叉树是否是同一个二叉树

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (p == NULL || q == NULL) return false;
        
        queue<TreeNode*> f1;
        queue<TreeNode*> f2;
        f1.push(p);
        f2.push(q);
        
        while (!f1.empty()) {
            TreeNode* pp = f1.front();
            TreeNode* pq = f2.front();
            f1.pop();
            f2.pop();
            if (pp->val != pq->val) return false;
            if (pp->left == NULL && pq->left != NULL || pp->left != NULL && pq->left == NULL) return false;
            if (pp->right == NULL && pq->right != NULL || pp->right != NULL && pq->right == NULL) return false;
            
            if (pp->left != NULL) {
                f1.push(pp->left);
                f2.push(pq->left);
            }
            
            if (pp->right != NULL) {
                f1.push(pp->right);
                f2.push(pq->right);
            }
        }
        
        return true;
    }
};
