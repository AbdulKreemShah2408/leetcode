class Solution {
public:
   void dfs(int i,vector<vector<int>>& adj,vector<int>& check){
       check[i]=1;
       for(auto it:adj[i]){
        if(!check[it]){
            dfs(it,adj,check);
        }
       }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>check(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(check[i] ==0){
                dfs(i,adj,check);
                count++;
            }
        }
        return count;
    }
};