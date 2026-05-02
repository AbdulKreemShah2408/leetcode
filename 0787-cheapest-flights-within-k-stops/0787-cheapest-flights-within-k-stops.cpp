class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto& flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});

        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto& iter:adj[node]){
                int adjNode=iter.first;
                int edgeWeight=iter.second;
                if(cost+edgeWeight<dist[adjNode]){
                    dist[adjNode]=cost+edgeWeight;
                  q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};