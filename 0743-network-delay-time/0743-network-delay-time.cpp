#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

      
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0; 

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

           
            if (d > dist[u]) continue;

           
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;


                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

       
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};