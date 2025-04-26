class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])){
                if(i-s[nums[i]]<=k){
                    return true;
                }
            }
            s[nums[i]]=i;
        }
        return false;
    }
};