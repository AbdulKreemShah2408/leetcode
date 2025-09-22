class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int>freqMap;
       int maxFreq=0;
       for(int x:nums){
       freqMap[x]++;
       maxFreq=max(maxFreq,freqMap[x]);
       }
       int total=0;
       for(auto &[key,val]:freqMap){
        if(val==maxFreq){
            total +=val;
        }

       }
       return total;
    }

};