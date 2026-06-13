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
    int totalPaths=0;
    unordered_map<long long,int>prefixSumMap;
    void solve(TreeNode* root,long long currentSum,int targetSum){
        if(root==nullptr) return;
        currentSum +=root->val;
        if(prefixSumMap.count(currentSum-targetSum)){
            totalPaths +=prefixSumMap[currentSum-targetSum];
        }
        prefixSumMap[currentSum]++;
        solve(root->left,currentSum,targetSum);
        solve(root->right,currentSum,targetSum);
        prefixSumMap[currentSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefixSumMap[0]=1;
        solve(root,0,targetSum);
        return totalPaths;
    }
};