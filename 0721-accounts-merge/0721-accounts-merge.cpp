class Solution {
public:
    void dfs(string& email,unordered_map<string,vector<string>>&adj,unordered_set<string>&visited,vector<string>& merged_emails){
        visited.insert(email);
        merged_emails.push_back(email);
        for(string& neighbor:adj[email]){
        if(!visited.count(neighbor)){
            dfs(neighbor,adj,visited,merged_emails);
        }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,string>email_to_name;
        for(auto& account:accounts){
            string name=account[0];
            string first_email=account[1];
            for(int i=1;i<account.size();i++){
                string current_email=account[i];
                adj[first_email].push_back(current_email);
                adj[current_email].push_back(first_email);
                email_to_name[current_email]=name;
            }
        }
        unordered_set<string>visited;
        vector<vector<string>>result;
        for(auto& pair:email_to_name){
            string email=pair.first;
            string name=pair.second;
            if(!visited.count(email)){
                vector<string>merged_emails;
                dfs(email,adj,visited,merged_emails);
                sort(merged_emails.begin(),merged_emails.end());
                vector<string>account_res;
                account_res.push_back(name);
                account_res.insert(account_res.end(),merged_emails.begin(),merged_emails.end());
                result.push_back(account_res);
            }
        }
        return result;
    }
};