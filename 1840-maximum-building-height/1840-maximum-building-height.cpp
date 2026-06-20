class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        int m=restrictions.size();
        for(int i=1;i<m;i++){
            int id1=restrictions[i-1][0];
            int h1=restrictions[i-1][1];
            int id2=restrictions[i][0];
            int h2=restrictions[i][1];
            int max_possible_h2=h1+(id2-id1);
            restrictions[i][1]=min(h2,max_possible_h2);
        }
        for(int i=m-2;i>=0;i--){
            int id1=restrictions[i][0];
            int h1=restrictions[i][1];
            int id2=restrictions[i+1][0];
            int h2=restrictions[i+1][1];
            int max_possible_h1=h2+(id2-id1);
            restrictions[i][1]=min(h1,max_possible_h1);
        }
        int max_height=0;
        for(int i=0;i<m-1;i++){
            int id1=restrictions[i][0];
            int h1=restrictions[i][1];
            int id2=restrictions[i+1][0];
            int h2=restrictions[i+1][1];
            int distance=id2-id1;
            int peak=(h1+h2+distance)/2;
            max_height=max(max_height,peak);
        }
        return max_height;
    }
};