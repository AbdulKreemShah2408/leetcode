class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        if(nums.empty()) return res;
       int n=nums.size();
       int start=0, end=n-1;
       while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
            if(nums[mid]==target){
                res[0]=mid;
            }
        }
       }
       if(res[0] == -1) return res;
        start=res[0];
       end=nums.size()-1;
       while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
            if(nums[mid]==target) res[1]=mid;
        }
       }
       return res;
    }
};