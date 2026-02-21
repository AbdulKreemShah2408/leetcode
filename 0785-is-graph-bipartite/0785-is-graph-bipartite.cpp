class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
        if(color[i] !=-1) continue;
        queue<int>q;
        q.push(i);
        color[i]=0;
         while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int neighbors:graph[curr]){
              if(color[neighbors]==-1)  {
             color[neighbors]=1-color[curr];
             q.push(neighbors);
              
            }else if(color[neighbors]==color[curr]){
                return false;
            }
            }
         }
        }
        return true;
    }
};