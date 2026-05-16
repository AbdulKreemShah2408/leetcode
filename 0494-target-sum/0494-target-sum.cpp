class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=0;
        for(int num:nums){
            totalSum +=num;
        }
        if(target>totalSum || target< -totalSum || (target+totalSum)%2 !=0){ 
            return 0;
        }
        int subSumTarget=(target+totalSum)/2;
        vector<int>dp(subSumTarget+1,0);
        dp[0]=1;
        for(int num:nums){
            for(int i=subSumTarget;i>=num;i--){
            dp[i] +=dp[i-num];
        }
        }
        return dp[subSumTarget];
    }
};