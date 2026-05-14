class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int max_num=n-1;
        for(int i=0;i<n-1;i++){
            if(nums[i] !=i+1){
                return false;
            }
        }
        if(nums[n-1]==max_num){
            return true;
        }
        return false;
    }
};