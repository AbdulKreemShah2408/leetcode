class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int totalSum=0;
        for(int weight:stones){
            totalSum +=weight;
        }
        int target=totalSum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
          int currentStone=stones[i-1];
          for(int j=1;j<=target;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=currentStone){
                dp[i][j]=dp[i][j] || dp[i-1][j-currentStone];

            }
          }
        }
        int s1=0;
        for(int j=target;j>=0;j--){
            if(dp[n][j]==true){
             s1=j;
             break;
            }
        }
        return totalSum-2*s1;
    }
};