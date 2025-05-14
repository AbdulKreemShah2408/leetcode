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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>result;
    if(root==NULL) return result;;
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    vector<int>currLevel;
    while(q.size()>0){
        TreeNode* curr=q.front();
        q.pop();
        if(curr==NULL){
            result.push_back(currLevel);
            currLevel.clear();
            if(!q.empty()){
                q.push(NULL);
                continue;
            }       
        }
         else{
                currLevel.push_back(curr->val);
                if(curr->left != NULL)
                 q.push(curr->left);
                  if(curr->right != NULL)
                 q.push(curr->right);
                 
            }
        
        
    }
   return result;
    }

};
