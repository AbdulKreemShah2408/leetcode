class Solution {
public:
  vector<vector<int>>result;
    void backtrack(vector<int>& candidates, vector<int>&current,int target,int start){
        if(target==0){
            result.push_back(current);
        }
        if(target<0){
            return;
        }
        for(int i=start;i<candidates.size();i++){
            current.push_back(candidates[i]);
            backtrack(candidates,current,target-candidates[i],i);
            current.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates , int target) {
    vector<int>current;
    backtrack(candidates,current,target,0);
    return result;
    }
};