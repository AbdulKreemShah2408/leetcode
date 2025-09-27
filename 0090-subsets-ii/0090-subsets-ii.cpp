class Solution {
public:
   vector<vector<int>>result;
   void backtrack(vector<int>& nums,vector<int>& current,int start){
    result.push_back(current);
    for(int i=start;i<nums.size();i++){
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        current.push_back(nums[i]);
        backtrack(nums,current,i+1);
        current.pop_back();
    }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>current;
        backtrack(nums,current,0);
        return result;
    }
};