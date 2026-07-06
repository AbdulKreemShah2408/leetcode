class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,vector<int>a_next){
            if(a[0]==a_next[0]){
                return a[1]>a_next[1];
            }
            return a[0]<a_next[0];
        });

       int reamining=0;
       int current_right=0;
       for(const auto& interval:intervals){
        if(interval[1]>current_right){
            reamining++;
            current_right=interval[1];
        }
       }
       return reamining;
    }
};