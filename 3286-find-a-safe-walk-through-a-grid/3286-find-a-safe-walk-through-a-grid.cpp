class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        int start_health=health-grid[0][0];
        if(start_health<=0) return false;
        vector<vector<int>>max_health(m,vector<int>(n,-1));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({start_health, {0, 0}});
        int dRow[]={-1,1,0,0};
        int dCol[]={0,0,-1,1};
        while(!pq.empty()){
            auto current=pq.top();
            pq.pop();
            int current_h=current.first;
            int r=current.second.first;
            int c=current.second.second;
            if(r==m-1 && c==n-1){
                return current_h>=1;
            }
            if(current_h<max_health[r][c]){
                continue;
            }
            for(int i=0;i<4;i++){
                int nRow=r+dRow[i];
                int nCol=c+dCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n){
                    int next_health=current_h-grid[nRow][nCol];
                    if(next_health>0 && next_health>max_health[nRow][nCol]){
                        max_health[nRow][nCol]=next_health;
                        pq.push({next_health,{nRow,nCol}});
                    }
                }
            }
        }
        return false;
    }
};