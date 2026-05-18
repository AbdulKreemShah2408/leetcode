class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>index;
        for(int i=0;i<arr.size();i++){
            index[arr[i]].push_back(i);
        }
        int n=arr.size();
        if(n==0) return 0;
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0]=true;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                if(curr==n-1) return steps;
                if(curr+1<n && !visited[curr+1]){
                    visited[curr+1]=true;
                    q.push(curr+1);
                }
                if(curr-1>=0 && !visited[curr-1]){
                    visited[curr-1]=true;
                    q.push(curr-1);
                }
                int value=arr[curr];
                for(int nextIndex:index[value]){
                    if(nextIndex !=curr && !visited[nextIndex]){
                        visited[nextIndex]=true;
                        q.push(nextIndex);
                    }
                }
                index[value].clear();
            }
            steps++;

        }
        return steps;
    }
};