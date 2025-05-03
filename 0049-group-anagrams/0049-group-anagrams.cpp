class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>m;
        for(auto it :strs){
            string temp=it;
            sort(it.begin(),it.end());
            m[it].push_back(temp);

        }
        vector<vector<string>>ans;
        for(auto x:m){
         ans.push_back(x.second);
        }
        return ans;
    }
};