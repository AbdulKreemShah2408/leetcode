class Solution {
public:
    bool dfs(int i,int j,string& s,string& p,vector<vector<int>>&dp){
        if(j==p.length()){
          return i==s.length();
        }
        if(dp[i][j] !=-1) return dp[i][j];
        bool firstMatch=(i<s.length() && (s[i]==p[j] || p[j]=='.'));
         if(j+1<p.length() && p[j+1]=='*'){
            bool skipStar=dfs(i,j+2,s,p,dp);
            bool useStar=firstMatch && dfs(i+1,j,s,p,dp);
            return dp[i][j]=(skipStar || useStar);
         }else{
            return dp[i][j]=firstMatch && dfs(i+1,j+1,s,p,dp);
         }
        
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dfs(0,0,s,p,dp);
    }
};