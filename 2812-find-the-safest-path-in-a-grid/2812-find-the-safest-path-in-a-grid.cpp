class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return 0;
        }
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int r=0;r<n;++r){
            for(int c=0;c<n;++c){
                if(grid[r][c]==1){
                    q.push({r,c});
                    dist[r][c]=0;
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>>maxHeap;
        maxHeap.push({dist[0][0],{0,0}});
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        while(!maxHeap.empty()){
            auto top=maxHeap.top();
            maxHeap.pop();
            int current_safeness=top.first;
            int r=top.second.first;
            int c=top.second.second;
            if(r==n-1 && c==n-1){
                return current_safeness;
            }
            for(int i=0;i<4;++i){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                   visited[nr][nc]=true;
                    int next_safeness=min(current_safeness,dist[nr][nc]);
                    maxHeap.push({next_safeness,{nr,nc}});
                }
            }
        }
        return 0;
    }
};