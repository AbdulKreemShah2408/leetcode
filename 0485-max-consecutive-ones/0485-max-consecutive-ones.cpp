class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCount=0;
        int maxCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currCount++;
            }
            else{
                maxCount=max(maxCount,currCount);
                currCount=0;
            }
        }
        maxCount=max(maxCount,currCount);
        return maxCount;
    }
};