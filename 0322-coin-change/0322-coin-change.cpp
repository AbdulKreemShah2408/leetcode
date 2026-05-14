class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_val=amount+1;
        vector<int>dp(amount+1,max_val);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int coin:coins){
                if(coin<=i){
                    dp[i]=min(dp[i],1+dp[i-coin]);

                }
            }
        }
        return dp[amount]>amount ? -1:dp[amount];
    }
};
