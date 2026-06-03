class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int min_land_finish=INT_MAX;
        int min_land_duration=INT_MAX;
        int min_land_total_finish=INT_MAX;
        for(int i=0;i<n;i++){
            min_land_finish=min(min_land_finish,landStartTime[i]+landDuration[i]);
            min_land_duration=min(min_land_duration,landDuration[i]);

        }
        int min_water_finish=INT_MAX;
        int min_water_duration=INT_MAX;
        for(int j=0;j<m;j++){
            min_water_finish=min(min_water_finish,waterStartTime[j]+waterDuration[j]);
            min_water_duration=min(min_water_duration,waterDuration[j]);
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            int current_finish=max(min_land_finish,waterStartTime[j])+waterDuration[j];
            ans=min(ans,current_finish);

        }
        for(int i=0;i<n;i++){
            int current_finish=max(min_water_finish,landStartTime[i])+landDuration[i];
            ans=min(ans,current_finish);
            
        }
        return ans;
    }
};