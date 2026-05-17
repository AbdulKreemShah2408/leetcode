class Solution {
public:
   bool dfs(vector<int>& arr,int curr,vector<bool>& visited){
    if(curr<0 || curr>=arr.size()) return false;
    if(visited[curr]==true) return false;
    if(arr[curr]==0) return true;
    visited[curr]=true;
   return  dfs(arr,curr+arr[curr],visited) || dfs(arr,curr-arr[curr],visited);
    
   }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>visited(n,false);
        return dfs(arr,start,visited);
    }
};