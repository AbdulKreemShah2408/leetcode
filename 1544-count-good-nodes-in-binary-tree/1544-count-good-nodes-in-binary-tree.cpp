/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int helper(TreeNode* root, int maxSoFar){
    if(!root) return 0;
    int count=0;
    if(root->val>=maxSoFar){
      count=1;
    }
    maxSoFar=max(maxSoFar,root->val);
    count +=helper(root->left,maxSoFar);
    count +=helper(root->right,maxSoFar);
    return count;
   }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};