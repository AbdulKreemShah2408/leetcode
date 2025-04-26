class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int,int>freq;
       vector<int>result;
       int n=nums.size();
       for(int num:nums){
        freq[num]++;
       }
       for(auto it:freq){
        if(it.second>n/3){
            result.push_back(it.first);
        }
       }
       return result;
    }
};