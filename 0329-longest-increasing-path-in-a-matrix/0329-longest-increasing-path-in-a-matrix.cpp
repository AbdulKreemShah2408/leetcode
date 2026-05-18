class Solution {
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

public:
    int dfs(int r,int c,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(dp[r][c] !=-1) return dp[r][c];
        int m=matrix.size();
        int n=matrix[0].size();
        int maxPath=1;
        for(int i=0;i<4;i++){
            int newR=r+dr[i];
            int newC=c+dc[i];
            if(newR>=0 && newR<m  && newC>=0 && newC<n && matrix[newR][newC]>matrix[r][c]){
                int currPath=1+dfs(newR,newC,matrix,dp);
                maxPath=max(maxPath,currPath);
            }
        }
        return dp[r][c]=maxPath;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int longestPath=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                longestPath=max(longestPath,dfs(i,j,matrix,dp));
            }
        }
        return longestPath;
    }
};