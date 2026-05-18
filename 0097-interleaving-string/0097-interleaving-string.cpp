class Solution {
public:
   bool solve(int i,int j,string& s1,string& s2,string& s3,vector<vector<int>>& dp){
    if(i==s1.length() && j==s2.length()){
        return true;
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    bool matchS1=false;
    bool matchS2=false;
    if(i<s1.length() && s1[i]==s3[i+j]){
        matchS1=solve(i+1,j,s1,s2,s3,dp);
    }
    if(j<s2.length() && s2[j]==s3[i+j]){
        matchS2=solve(i,j+1,s1,s2,s3,dp);
    }
    return dp[i][j]=(matchS1 || matchS2);
   }
    bool isInterleave(string s1, string s2, string s3) {
     if(s1.length()+s2.length() !=s3.length()){
        return false;
     }   
     int n=s1.length();
     int m=s2.length();
     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     return solve(0,0,s1,s2,s3,dp);
    }
};
