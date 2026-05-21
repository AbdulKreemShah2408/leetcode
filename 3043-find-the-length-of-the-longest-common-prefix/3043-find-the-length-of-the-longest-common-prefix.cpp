#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    
    struct TrieNode {
        TrieNode* children[10] = {nullptr}; 
    };

    TrieNode* root;

   
    void insert(int num) {
        TrieNode* curr = root;
        std::string str = std::to_string(num); 
        
        for (char ch : str) {
            int digit = ch - '0';
            if (curr->children[digit] == nullptr) {
                curr->children[digit] = new TrieNode();
            }
            curr = curr->children[digit];
        }
    }


    int getCommonPrefixLength(int num) {
        TrieNode* curr = root;
        std::string str = std::to_string(num);
        int length = 0;
        
        for (char ch : str) {
            int digit = ch - '0';
           
            if (curr->children[digit] != nullptr) {
                length++;
                curr = curr->children[digit];
            } else {
                break;
            }
        }
        return length;
    }

public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
   
        root = new TrieNode();
        
        
        for (int num : arr1) {
            insert(num);
        }
        
        int max_longest_prefix = 0;
        
       
        for (int num : arr2) {
            max_longest_prefix = std::max(max_longest_prefix, getCommonPrefixLength(num));
        }
        
        return max_longest_prefix;
    }
};