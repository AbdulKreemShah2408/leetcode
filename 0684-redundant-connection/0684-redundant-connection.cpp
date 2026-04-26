class Solution {
public:
   bool hasPath(int curr,int target,unordered_map<int,vector<int>>& adj,unordered_set<int>& visited){
    if(curr==target) return true;
    visited.insert(curr);
    for(int neighbor:adj[curr]){
        if(visited.find(neighbor)==visited.end()){
            if(hasPath(neighbor,target,adj,visited)){
                return true;
            }
        }
    }
    return false;
   }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            unordered_set<int>visited;
            if(adj.count(u) && adj.count(v) && hasPath(u,v,adj,visited)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return {};
    }
};
