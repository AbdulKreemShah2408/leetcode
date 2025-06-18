class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int currGain=0;
        int maxGain=0;
        for(int i=0;i<n;i++){
            currGain +=gain[i];
            maxGain=max(maxGain,currGain);
        }
        return maxGain;
    }
};