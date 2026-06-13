class Solution {
public:
    bool canPartation(int index,vector<int>&nums,vector<int>&subsets,int target){
        if(index==nums.size()) return true;
        for(int i=0;i<subsets.size();i++){
            if(subsets[i]+nums[index]<=target){
             subsets[i] +=nums[index];
             if(canPartation(index+1,nums,subsets,target)){
                return true;
             }
             subsets[i] -=nums[index];
            }
            if(subsets[i]==0) break;
            if(i>0 && subsets[i]==subsets[i-1]) continue;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      if(nums.size()<k) return false;
       int totalSum=0;
       for(int num:nums){
        totalSum +=num;
       }  
       if(totalSum%k !=0) return false;
       int target=totalSum/k;
       sort(nums.rbegin(),nums.rend());
       if(nums[0]>target) return false;
       vector<int>subsets(k,0);
       return canPartation(0,nums,subsets,target);
    
    }
};