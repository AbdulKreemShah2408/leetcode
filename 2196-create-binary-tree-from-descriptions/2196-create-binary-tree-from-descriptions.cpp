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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>node_map;
        unordered_set<int>child_set;
        for(auto& des:descriptions){
            int p_val=des[0];
            int c_val=des[1];
            int isLeft=des[2];
            if(node_map.find(p_val) == node_map.end()){
               node_map[p_val]=new TreeNode(p_val);
            }
             if(node_map.find(c_val) == node_map.end()){
               node_map[c_val]=new TreeNode(c_val);
            }
            if(isLeft==1){
                node_map[p_val]->left=node_map[c_val];

            }else{
                node_map[p_val]->right=node_map[c_val];
            }
            child_set.insert(c_val);
        }
        for(auto& pair:node_map){
            int curr_val=pair.first;
            if(child_set.find(curr_val) == child_set.end()){
                return pair.second;
            }
        }
        return nullptr;
    }
};