class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
          totalSum +=nums[i];
        }
        int leftSum=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int rightSum=totalSum-leftSum-nums[i];
            ans[i]=abs(leftSum-rightSum);
            leftSum +=nums[i];
        }
        return ans;
    }
};