class Solution {
public:
    vector<int>topoSort(int k,vector<vector<int>>&conditions){
        vector<vector<int>>adj(k+1);
        vector<int>indegree(k+1,0);
        for(auto& cond:conditions){
            int u=cond[0];
            int v=cond[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>order;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(int neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        if(order.size() !=k) return {};
            return order;
        

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowOrder=topoSort(k,rowConditions);
        vector<int>colOrder=topoSort(k,colConditions);
        if(rowOrder.empty() ||  colOrder.empty()) return {};
        vector<int>rowPos(k+1),colPos(k+1);
        for(int i=0;i<k;i++){
            rowPos[rowOrder[i]]=i;
            colPos[colOrder[i]]=i;

        }
        vector<vector<int>>matrix(k,vector<int>(k,0));
        for(int num=1;num<=k;num++){
            int r=rowPos[num];
            int c=colPos[num];
            matrix[r][c]=num;

        }
        return matrix;
    }
};