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
    int maxPathSum(TreeNode* root) {
       int res=INT_MIN;
       findMax(root,res);
       return res;
    }
    int findMax(TreeNode* node,int &res){
        if(node==NULL) return 0;
        int left=max(0,findMax(node->left,res));
        int right=max(0,findMax(node->right,res));
        res=max(res,node->val+left+right);
        return node->val+max(left,right);
    }
};
