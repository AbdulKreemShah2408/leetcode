class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;

        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        int remaing_nodes=n;
        while(remaing_nodes>2){
            int size=q.size();
            remaing_nodes -=size;
            for(int i=0;i<size;i++){
                int leaf=q.front();
                q.pop();
                for(int neighbor:adj[leaf]){
                    degree[neighbor]--;
                    if(degree[neighbor]==1){
                        q.push(neighbor);
                    }

                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    

};