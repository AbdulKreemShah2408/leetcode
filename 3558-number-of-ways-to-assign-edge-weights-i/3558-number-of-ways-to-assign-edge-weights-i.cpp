class Solution {
    private:
    long long power(long long base,long long exp,long long mod){
        long long res=1;
        base %=mod;
        while(exp>0){
            if(exp%2==1) res=(res*base)%mod;
            base=(base*base)%mod;
            exp /=2;
        }
        return res;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        long long MOD=1e9+7;
        vector<vector<int>>adj(n+1);
        for(const auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>>q;
        vector<bool>visited(n+1,false);
        q.push({1,0});
        visited[1]=true;
        int max_edges=0;
        while(!q.empty()){
            auto [current_node,current_edges]=q.front();
            q.pop();
            max_edges=max(max_edges,current_edges);
            for(int neighbor:adj[current_node]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push({neighbor,current_edges+1});

                }
            }
        }
        if(max_edges==0) return 0;
        return power(2,max_edges-1,MOD);
    }
};