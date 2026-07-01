class Solution {
public:
   int dp[101][101];
   int suffixSum[101];
   int n;
   int solve(int i,int M,vector<int>&piles){
    if(i>=n) return 0;
    if(i+2*M>=n){
     return suffixSum[i];
    }
    if(dp[i][M] !=-1) return dp[i][M];
    int maxStones=0;
    for(int X=1;X<=2*M;++X){
        int currentScore=suffixSum[i]-solve(i+X,max(M,X),piles);
        maxStones=max(maxStones,currentScore);

    }
    return dp[i][M]=maxStones;
   }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j]=-1;
            }
        }
        suffixSum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;--i){
           suffixSum[i]=suffixSum[i+1]+piles[i];
        }
        return solve(0,1,piles);
    }
};