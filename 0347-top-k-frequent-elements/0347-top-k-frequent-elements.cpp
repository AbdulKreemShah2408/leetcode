class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>countMap;
        for(int num:nums){
            countMap[num]++;
        }
        vector<vector<int>>buckets(n+1);
        for(auto& it:countMap){
            int num=it.first;
            int freq=it.second;
            buckets[freq].push_back(num);
        }
        vector<int>result;
        for(int i=n;i>=0;i--){
           for(int num:buckets[i]){
             result.push_back(num);
            if(result.size()==k){
                return result;
            }
           }
        }
        return result;
    }
};