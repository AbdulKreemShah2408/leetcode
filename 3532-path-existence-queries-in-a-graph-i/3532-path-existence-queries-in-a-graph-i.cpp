class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>group(n,0);
        int current_group=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                current_group++;
            }
            group[i]=current_group;
        }
        vector<bool>ans;
        ans.reserve(queries.size());
        for(const auto& query:queries){
            int u=query[0];
            int v=query[1];
            if(group[u]==group[v]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};