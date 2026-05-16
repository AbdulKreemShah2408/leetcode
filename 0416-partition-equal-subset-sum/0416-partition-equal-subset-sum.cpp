class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int num:nums){
            totalSum +=num;
        }
        if(totalSum%2 !=0){
            return false;
        }
        int target=totalSum/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int i=target;i>=num;i--){
                if(dp[i-num]){
                    dp[i]=true;
                }
            }
        }
        return dp[target];
    }
};