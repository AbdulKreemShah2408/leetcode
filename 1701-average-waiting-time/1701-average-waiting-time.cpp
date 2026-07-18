class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWait=0;
        int currentTime=0;
        for(const auto& c:customers){
            int arrival=c[0];
            int duration=c[1];
            int start_time=max(arrival,currentTime);
            int finish_time=start_time+duration;
            totalWait +=(finish_time-arrival);
            currentTime=finish_time;
        }
        return totalWait/customers.size();
    }
};