class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};
class Solution {
public:
   int findMSTWeight(int n,vector<vector<int>>& edges,int skip_edge_idx,int force_edge_idx){
    DSU dsu(n);
    int weight=0;
    int edges_count=0;
    if(force_edge_idx !=-1){
        for(auto& edge:edges){
            if(edge[3]==force_edge_idx){
                dsu.unite(edge[0],edge[1]);
            weight +=edge[2];
            edges_count++;
            break;
            }
        }
    }
    for(auto& edge:edges){
        if(edge[3]==skip_edge_idx) continue;
        if(dsu.unite(edge[0],edge[1])){
            weight +=edge[2];
            edges_count++;
        }
    }
    if(edges_count !=n-1) return INT_MAX;
    return weight;
}

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](const vector<int>& a,const vector<int>&b){
            return a[2]<b[2];
        });
        int original_mst=findMSTWeight(n,edges,-1,-1);
        vector<int>critical,pseude_critical;
        for(int i=0;i<edges.size();i++){
            int original_idx=edges[i][3];
            if(findMSTWeight(n,edges,original_idx,-1)>original_mst){
                critical.push_back(original_idx);
            }else if(findMSTWeight(n,edges,-1,original_idx)==original_mst){
                pseude_critical.push_back(original_idx);
            }
        }
        return {critical,pseude_critical};
    }
};