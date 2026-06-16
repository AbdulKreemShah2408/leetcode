class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>>isPre(numCourses,vector<bool>(numCourses,false));
        for(auto& pre:prerequisites){
            int courseA=pre[0];
            int courseB=pre[1];
            isPre[courseA][courseB]=true;
        }
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    if(isPre[i][k] && isPre[k][j]){
                        isPre[i][j]=true;
                    }
                }
            }
        }
        vector<bool>ans;
        for(auto& query:queries){
            int u=query[0];
            int v=query[1];
            ans.push_back(isPre[u][v]);
        }
        return ans;
    }
};