class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(n,false);
        int complete_count=0;
        for(int i=0;i<n;++i){
          if(!visited[i]){
            vector<int>component;
            vector<int>stack;
            stack.push_back(i);
            visited[i]=true;
            while(!stack.empty()){
                int u=stack.back();
                stack.pop_back();
                component.push_back(u);
                for(int v:adj[u]){
                    if(!visited[v]){
                        visited[v]=true;
                        stack.push_back(v);
                    }
                }
            }
                long long v_count=component.size();
                long long e_count=0;
                for(int node:component){
                    e_count +=adj[node].size();

                }
                e_count /=2;
                if(e_count==(v_count*(v_count-1))/2){
                    complete_count++;
                }
            }
          
        }
        return complete_count;

    }
};