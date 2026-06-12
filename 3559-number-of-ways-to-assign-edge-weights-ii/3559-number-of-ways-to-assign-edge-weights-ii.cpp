#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    const int MOD = 1e9 + 7;

    void dfs(int u, int p, int d) {
        depth[u] = d;
        up[u][0] = p;
        
        for (int i = 1; i < LOG; ++i) {
            if (up[u][i-1] != -1) {
                up[u][i] = up[up[u][i-1]][i-1];
            } else {
                up[u][i] = -1;
            }
        }
        
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = 0;
        while ((1 << LOG) <= n) {
            LOG++;
        }
        LOG++;

        adj.assign(n + 1, vector<int>());
        up.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(1, -1, 0);
        
        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (u == v) {
                answer.push_back(0);
                continue;
            }
            
            int lca = get_lca(u, v);
            int k = depth[u] + depth[v] - 2 * depth[lca];
            
            answer.push_back(power(2, k - 1));
        }
        
        return answer;
    }
};