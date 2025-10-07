class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
         int start=0, end=n-1;
         while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==mid){
                start=mid+1;
            }
            else{
                end=mid-1;
            }

         }
         return start;

    }
};