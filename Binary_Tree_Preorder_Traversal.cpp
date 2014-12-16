#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> v;
      if (root==NULL) return v;
      stack<TreeNode*> s;
      s.push(root);
      while(!s.empty()) {
        TreeNode* left = s.top()->left;
        TreeNode* right = s.top()->right;
        v.push_back(s.top()->val);
        s.pop();
        if (right!=NULL) {
          s.push(right);
        }
        if (left!=NULL) {
          s.push(left);
        }
      }
      return v;
    }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  vector<int> p = (new Solution)->postorderTraversal(root);
  for(int i=0; i<p.size(); i++) {
    cout<<"val: "<<p[i]<<endl;
  }
}
