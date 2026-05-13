class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int maxSo=nums[0];
        int minSo=nums[0];
        int result=maxSo;
        for(int i=1;i<n;i++){
            int curr=nums[i];
            if(curr<0){
                swap(maxSo,minSo);
            }
            maxSo=max(curr,maxSo* curr);
            minSo=min(curr,minSo* curr);
            result=max(result,maxSo);
        }
        return result;

    }
};
