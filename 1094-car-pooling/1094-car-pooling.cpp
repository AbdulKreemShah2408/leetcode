class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>km(1001,0);
        for(const auto& trip:trips){
            int passengers=trip[0];
            int start=trip[1];
            int end=trip[2];
            km[start] +=passengers;
            km[end] -=passengers;
        }
        int current_passengers=0;
        for(int i=0;i<1000;i++){
            current_passengers +=km[i];
            if(current_passengers>capacity){
                return false;
            }
        }
        return true;
    }
};