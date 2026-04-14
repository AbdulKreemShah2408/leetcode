class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>sortedQueries;
        for(int i=0;i<queries.size();i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(),sortedQueries.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res(queries.size(),-1);
        int i=0;
        for(auto& qry:sortedQueries){
            int qVal=qry.first;
            int qIdx=qry.second;
            while(i<intervals.size() && intervals[i][0]<=qVal){
                int l=intervals[i][0];
                int r=intervals[i][1];
                pq.push({r-l+1,r});
                i++;
            }
            while(!pq.empty() && pq.top().second<qVal){
                pq.pop();
            }
         if(!pq.empty()){
            res[qIdx]=pq.top().first;
         }
        }
        return res;
    }
};
