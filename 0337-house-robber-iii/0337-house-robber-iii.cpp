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
    private:
    vector<int>robHelper(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        vector<int>leftChoice=robHelper(root->left);
        vector<int>rightChoice=robHelper(root->right);
        int choose_node=root->val+leftChoice[1]+rightChoice[1];
        int skip_node=max(leftChoice[0],leftChoice[1]) + max(rightChoice[0],rightChoice[1]);
        return {choose_node,skip_node};
    }
public:
    int rob(TreeNode* root) {
        vector<int>result=robHelper(root);
        return max(result[0],result[1]);
    }
};