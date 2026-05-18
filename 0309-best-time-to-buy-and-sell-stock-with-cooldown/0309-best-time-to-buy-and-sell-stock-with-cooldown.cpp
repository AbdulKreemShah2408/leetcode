class Solution {
public:
   int solve(int i,int buying,vector<int>& prices,vector<vector<int>>& dp){
    if(i>=prices.size()) return 0;
    if(dp[i][buying] !=-1){
        return dp[i][buying];
        
    }
    if(buying==1){
        int buyToday=-prices[i]+solve(i+1,0,prices,dp);
        int skipToday=solve(i+1,1,prices,dp);
        return dp[i][buying]=max(buyToday,skipToday);
    }
    else{
        int sellToday=prices[i]+solve(i+2,1,prices,dp);
        int skipToday=solve(i+1,0,prices,dp);
        return dp[i][buying]=max(sellToday,skipToday);
    }
   }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
