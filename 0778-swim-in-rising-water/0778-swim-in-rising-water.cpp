class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        pq.push({grid[0][0],0,0});
        visited[0][0]=true;
        int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int minTime=0;
        while(!pq.empty()){
            vector<int>current=pq.top();
            pq.pop();
            int elevation=current[0];
            int r=current[1];
            int c=current[2];
            minTime=max(minTime,elevation);
            if(r==n-1 && c==n-1){
                return minTime;
            }
            for(auto& dir:directions){
                int nr=r+dir[0];
                int nc=c+dir[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                    visited[nr][nc]=true;
                    pq.push({grid[nr][nc],nr,nc});

                }
            }
        }
        return minTime;
    }
};
