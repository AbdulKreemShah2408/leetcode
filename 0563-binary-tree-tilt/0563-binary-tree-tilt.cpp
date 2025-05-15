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
int totaltilt=0;
   int dfs(TreeNode* root){
   if(!root) return 0;
   int lefttilt=dfs(root->left);
   int righttilt=dfs(root->right);
    totaltilt +=abs(lefttilt-righttilt);
    return lefttilt+righttilt+root->val;
   }
    int findTilt(TreeNode* root) {
        dfs(root);
        return totaltilt;
    }
};