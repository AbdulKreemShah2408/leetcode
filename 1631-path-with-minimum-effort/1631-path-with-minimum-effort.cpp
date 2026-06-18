class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>effort(rows,vector<int>(cols,INT_MAX));
        effort[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==rows-1 && c==cols-1) return diff;
            for(int i=0;i<4;i++){
                int newR=r+dr[i];
                int newC=c+dc[i];
                if(newR>=0 && newR<rows && newC>=0 && newC<cols){
                    int newEffort=max(diff,abs(heights[r][c]-heights[newR][newC]));
                    if(newEffort<effort[newR][newC]){
                        effort[newR][newC]=newEffort;
                        pq.push({newEffort,{newR,newC}});
                    }
                }
            }
        }
        return 0;
    }
};