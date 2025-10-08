class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      unordered_map<int,int>freq;
      vector<int>result;
      for(auto num:nums){
        freq[num]++;
      }
      int n=nums.size();
      for(auto it:freq){
        if(it.second>n/3){
        result.push_back(it.first);
        }
      }
      return result;
    }
};