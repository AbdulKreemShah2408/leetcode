class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>graph;
    void dfs(string airport){
        while(!graph[airport].empty()){
            string next=graph[airport].top();
            graph[airport].pop();
            dfs(next);
        }
        result.push_back(airport);

    }
    vector<string>result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& t:tickets){
            graph[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};