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
  vector<int>modes;
  int maxcount=0;
  int count=0;
  TreeNode* prev=NULL;
   void inorder(TreeNode* root){
    if(!root) return ;
    inorder(root->left);
    if(prev && prev->val==root->val){
        count++;
    }
    else{
        count=1;
    }
    if(count>maxcount){
        maxcount=count;
        modes.clear();
        modes.push_back(root->val);
    }else if(count==maxcount){
        modes.push_back(root->val);
    }
    prev=root;
    inorder(root->right);
   }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
        
    }
};