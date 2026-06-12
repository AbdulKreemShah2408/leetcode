class Solution {
    private:
     vector<vector<int>>result;
     void backtrack(int start,int n,int k,vector<int>&current){
        if(current.size()==k){
            result.push_back(current);
            return;
        }
        for(int i=start;i<=n;++i){
            current.push_back(i);
            backtrack(i+1,n,k,current);
            current.pop_back();
        }
     }
public:

    vector<vector<int>> combine(int n, int k) {
        result.clear();
        vector<int>current;
        backtrack(1,n,k,current);
        return result;
    }
};