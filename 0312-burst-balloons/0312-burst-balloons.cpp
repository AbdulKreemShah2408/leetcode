class Solution {
public:
    int solve(int left,int right,vector<int>& nums,vector<vector<int>>&dp){
        if(left>right) return 0;
        if(dp[left][right] !=-1) return dp[left][right];
        int maxCoin=0;
        for(int i=left;i<=right;i++){
            int currCoins=nums[left-1]*nums[i]*nums[right+1];
            int leftCoins=solve(left,i-1,nums,dp);
            int rightCoins=solve(i+1,right,nums,dp);
            int total=currCoins+leftCoins+rightCoins;
            maxCoin=max(maxCoin,total);

        }
        return dp[left][right]=maxCoin;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        arr.push_back(1);
        for(int x:nums) arr.push_back(x);
        arr.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(1,n,arr,dp);
    }
};