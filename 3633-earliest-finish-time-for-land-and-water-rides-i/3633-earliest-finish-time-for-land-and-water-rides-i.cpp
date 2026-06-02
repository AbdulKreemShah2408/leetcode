class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int minFinishTime=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int landFinish1=landStartTime[i]+landDuration[i];
                int waterStart1=max(landFinish1,waterStartTime[j]);
                int totalFinish1=waterStart1+waterDuration[j];
                int waterFinish2=waterStartTime[j]+waterDuration[j];
                int landStart2=max(waterFinish2,landStartTime[i]);
                int totalFinish2=landStart2+landDuration[i];
                minFinishTime=min({minFinishTime,totalFinish1,totalFinish2});
            }
        }
        return minFinishTime;
    }
};