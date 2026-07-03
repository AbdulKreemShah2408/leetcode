struct Edge {
    int to;
    long long cost;
};
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<Edge>>adj(n);
        for(const auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            long long cost=edge[2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,cost});

        }
        vector<int>inDegree(n,0);
        for(int u=0;u<n;++u){
            for(const auto& edge:adj[u]){
                inDegree[edge.to]++;

            }
        }
        vector<int>topoOrder;
        vector<int>queue;
        for(int i=0;i<n;++i){
            if(inDegree[i]==0){
                queue.push_back(i);
            }
        }
        int head = 0;
        while (head < queue.size()) {
            int u = queue[head++];
            topoOrder.push_back(u);
            for (const auto& edge : adj[u]) {
                if (--inDegree[edge.to] == 0) {
                    queue.push_back(edge.to);
                }
            }
        }
        long long low = 0, high = 0;
        for (const auto& edge : edges) {
            high = max(high, (long long)edge[2]);
        }

        int ans = -1;
        const long long INF = 1e18;
        auto isValid = [&](long long mid_score) {
            vector<long long> min_cost(n, INF);
            min_cost[0] = 0;
            for (int u : topoOrder) {
                if (min_cost[u] == INF) continue;

                for (const auto& edge : adj[u]) {
                    
                    if (edge.cost < mid_score) continue;

                    if (min_cost[u] + edge.cost < min_cost[edge.to]) {
                        min_cost[edge.to] = min_cost[u] + edge.cost;
                    }
                }
            }
            return min_cost[n - 1] <= k;
        };
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isValid(mid)) {
                ans=mid;
                low = mid + 1;
            } else {
                high = mid - 1;   
            }
        }

        return ans;
    }
};