class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& road:roads){
            int u=road[0];
            int v=road[1];
            int dist=road[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        vector<bool>visited(n+1,false);
        int min_score=INT_MAX;
        queue<int>q;
        q.push(1);
        visited[1]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& neighbor:adj[node]){
                int next_node=neighbor.first;
                int dist=neighbor.second;
                min_score=min(min_score,dist);
                if(!visited[next_node]){
                    visited[next_node]=true;
                    q.push(next_node);
                }
            }
        }
        return min_score;

    }
};