class Solution {
public:
    void dfs(int r,int c,vector<vector<bool>>&visited,int prevHeight,vector<vector<int>>& heights){
        int rows=heights.size();
        int cols=heights[0].size();
        if(r<0 || c<0 || r>=rows || c>=cols || visited[r][c] || heights[r][c]<prevHeight ){
            return;
        }
        visited[r][c]=true;
        dfs(r+1,c,visited,heights[r][c],heights);
        dfs(r-1,c,visited,heights[r][c],heights);
        dfs(r,c-1,visited,heights[r][c],heights);
        dfs(r,c+1,visited,heights[r][c],heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
        if(heights.empty()) return result;
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<bool>>pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>>atlantic(rows,vector<bool>(cols,false));
        for(int c=0;c<cols;c++){
            dfs(0,c,pacific,heights[0][c],heights);
            dfs(rows-1,c,atlantic,heights[rows-1][c],heights);

        }
        for(int r=0;r<rows;r++){
            dfs(r,0,pacific,heights[r][0],heights);
            dfs(r,cols-1,atlantic,heights[r][cols-1],heights);
        }
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
};