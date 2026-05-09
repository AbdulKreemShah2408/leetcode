class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int num_layers=min(m,n)/2;
        for(int layer=0;layer<num_layers;++layer){
        vector<int>element;
        for(int j=layer;j<n-1-layer;++j) element.push_back(grid[layer][j]);
        for(int i=layer;i<m-1-layer;++i) element.push_back(grid[i][n-1-layer]);
        for(int j=n-1-layer;j>layer;--j) element.push_back(grid[m-1-layer][j]);
        for(int i=m-1-layer;i>layer;--i) element.push_back(grid[i][layer]);
        int total_elements=element.size();
        int net_roatations=k%total_elements;
        int idx=0;
        auto getNextVal=[&](){
            int val= element[(idx+net_roatations)%total_elements];
            idx++;
            return val;
        };
        for(int j=layer;j<n-1-layer;++j) grid[layer][j]=getNextVal();
        for(int i=layer;i<m-1-layer;++i) grid[i][n-1-layer]=getNextVal();
        for(int j=n-1-layer;j>layer;--j) grid[m-1-layer][j]=getNextVal();
        for(int i=m-1-layer;i>layer;--i) grid[i][layer]=getNextVal();

        }
        return grid;
    }

};