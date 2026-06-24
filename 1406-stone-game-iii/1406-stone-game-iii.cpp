class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int takeSum=0;
            int maxLead=INT_MIN;
            for(int k=0;k<3 && i+k<n;k++){
                takeSum +=stoneValue[i+k];
                int currentLead=takeSum-dp[i+k+1];
                maxLead=max(maxLead,currentLead);
            }
            dp[i]=maxLead;
        }
        if(dp[0]>0) return "Alice";
        if(dp[0]<0) return "Bob";
        return "Tie";

    }
};