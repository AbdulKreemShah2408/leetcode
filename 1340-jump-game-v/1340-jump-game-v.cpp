class Solution {
    
public:
   int dfs(int i,vector<int>& arr,int d,vector<int>& dp){
    if(dp[i] !=-1) return dp[i];
    int ans=1;
    int n=arr.size();
    for(int j=i+1;j<=min(i+d,n-1);++j){
        if(arr[i]>arr[j]){
            ans=max(ans,1+dfs(j,arr,d,dp));
        }else{
            break;
        }
    }
    for(int j=i-1;j>=max(0,i-d);--j){
        if(arr[i]>arr[j]){
            ans=max(ans,1+dfs(j,arr,d,dp));
        }else{
            break;
        }
    }
    return dp[i]=ans;
   }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int>dp(n,-1);
        int max_total_visited=0;
        for(int i=0;i<n;i++){
            max_total_visited=max(max_total_visited,dfs(i,arr,d,dp));
        }
        return max_total_visited;
    }
};