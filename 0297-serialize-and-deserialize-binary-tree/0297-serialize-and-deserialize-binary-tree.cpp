/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "N,";
        string s=to_string(root->val) + ",";
        s +=serialize(root->left);
        s +=serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    TreeNode* decode(stringstream& ss){
        string val;
        getline(ss,val,',');
        if(val=="N") return NULL;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=decode(ss);
        root->right=decode(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));