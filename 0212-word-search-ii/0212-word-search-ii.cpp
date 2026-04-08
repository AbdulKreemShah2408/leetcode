#include <vector>
#include <string>

using namespace std;


struct TrieNode {
    TrieNode* children[26];
    string word = ""; 

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {

    void insert(TrieNode* root, string& w) {
        TrieNode* curr = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = w; 
    }

   
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& result) {
        char c = board[i][j];
        
    
        if (c == '#' || !curr->children[c - 'a']) return;

        curr = curr->children[c - 'a'];
        
       
        if (curr->word != "") {
            result.push_back(curr->word);
            curr->word = ""; 
        }

        
        board[i][j] = '#';

        
        if (i > 0) dfs(board, i - 1, j, curr, result); 
        if (i < board.size() - 1) dfs(board, i + 1, j, curr, result); 
        if (j > 0) dfs(board, i, j - 1, curr, result); 
        if (j < board[0].size() - 1) dfs(board, i, j + 1, curr, result); 

        
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            insert(root, w);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

       
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};