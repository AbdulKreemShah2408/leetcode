class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int total_cost=0;
        int connected_edges=0;
        vector<int>minDist(n,INT_MAX);
        vector<bool>visited(n,false);
        minDist[0]=0;
        while(connected_edges<n){
            int currPoint=-1;
            int currMinWeight=INT_MAX;
            for(int i=0;i<n;i++){
                if(!visited[i] && minDist[i]<currMinWeight){
                    currMinWeight=minDist[i];
                    currPoint=i;
                }
            }
            total_cost +=currMinWeight;
            visited[currPoint]=true;
            connected_edges++;
            for(int nextPoint=0;nextPoint<n;nextPoint++){
                if(!visited[nextPoint]){
                    int dist=abs(points[currPoint][0]-points[nextPoint][0])+abs(points[currPoint][1]-points[nextPoint][1]);
                    if(dist<minDist[nextPoint]){
                        minDist[nextPoint]=dist;
                    }
                }
            }
        }
        return total_cost;

    }
};
