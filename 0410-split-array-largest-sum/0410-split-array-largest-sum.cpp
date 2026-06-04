class Solution {
public:
   bool canSpilit(vector<int>&nums,int maxAllowed,int k){
    int subarrayCount=1;
    int currentSum=0;
    for(int num:nums){
        if(num>maxAllowed) return false;
        if(currentSum+num>maxAllowed){
            subarrayCount++;
            currentSum =num;
        }else{
            currentSum +=num;
        }
    }
    return subarrayCount<=k;
   }
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        for(int num:nums){
            low=max(low,num);
            high +=num;
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canSpilit(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};