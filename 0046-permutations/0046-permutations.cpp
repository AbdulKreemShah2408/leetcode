class Solution {
public:
   void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>arr,vector<bool>& used){
    if(arr.size()==nums.size()){
        ans.push_back(arr);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]==false){
            used[i]=true;
            arr.push_back(nums[i]);
            solve(nums,ans,arr,used);
            arr.pop_back();
            used[i]=false;
        }
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int>arr;
       vector<bool>sit(nums.size(),false);
       solve(nums,ans,arr,sit);
       return ans; 
    }
};