class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>& a, const vector<int>& b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        int totalEnergy=0;
        int currEnergy=0;
        for(auto& t:tasks){
            int actual=t[0];
            int min=t[1];
         if(currEnergy<min){
            totalEnergy +=(min-currEnergy);
            currEnergy=min;

         }   
         currEnergy -=actual;
        }
        return totalEnergy;
    }
};