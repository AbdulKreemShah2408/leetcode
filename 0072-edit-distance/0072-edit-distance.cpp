class Solution {
public:
    int dfs(int i,int j,string& word1,string& word2,vector<vector<int>>&dp){
        if(i==word1.length()) return word2.length()-j;
        if(j==word2.length()) return word1.length()-i;
        if(dp[i][j] !=-1) return dp[i][j];
        if(word1[i]==word2[j]){
          return dp[i][j]=  dfs(i+1,j+1,word1,word2,dp);

        }else{
           int insetOp= dfs(i,j+1,word1,word2,dp);
           int deleteOp= dfs(i+1,j,word1,word2,dp);
           int replaceOp=dfs(i+1,j+1,word1,word2,dp);
           return dp[i][j]=1+min({insetOp,deleteOp,replaceOp});
        }
        
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n,-1));
        return dfs(0,0,word1,word2,dp);
    }
};