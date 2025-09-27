class Solution {
public:
  vector<vector<int>>result;
   void backtrack(vector<int>& nums,vector<int>& current,vector<bool>& used){
    if(current.size()==nums.size()){
        result.push_back(current);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]){
            continue;
        }
        used[i]=true;
        current.push_back(nums[i]);
        backtrack(nums,current,used);
        current.pop_back();
        used[i]=false;
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<int>current;
      vector<bool>used(nums.size(),false);
      backtrack(nums,current,used);
      return result;
    }
};