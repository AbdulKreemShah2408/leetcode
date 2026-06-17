class Solution {
public:
   double dfs(string src,string dst,unordered_set<string>&visited, unordered_map<string,vector<pair<string,double>>>&adj){
     if(src==dst) return 1.0;
     visited.insert(src);
     for(auto& neighbor:adj[src]){
        string next_node=neighbor.first;
        double weight=neighbor.second;
        if(!visited.count(next_node)){
            double res=dfs(next_node,dst,visited,adj);
            if(res !=-1.0){
                return weight*res;
            }
        }
     }
     return -1.0;
   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});

        }
        vector<double>final_ans;
        for(auto& query:queries){
            string src=query[0];
            string dst=query[1];
            if(!adj.count(src) || !adj.count(dst)){
                final_ans.push_back(-1.0);
            }else{
                unordered_set<string>visited;
                double result=dfs(src,dst,visited,adj);
                final_ans.push_back(result);
            }
        }
        return final_ans;
    }
};