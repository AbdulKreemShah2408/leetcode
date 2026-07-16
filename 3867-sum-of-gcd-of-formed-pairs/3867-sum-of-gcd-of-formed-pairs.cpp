class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGrid;
        int currentMax=0;
        for(int i=0;i<n;++i){
            currentMax=max(currentMax,nums[i]);
            prefixGrid.push_back(gcd(nums[i],currentMax));
        }
        sort(prefixGrid.begin(),prefixGrid.end());
        long long totalSum=0;
        int left=0;
        int right=n-1;
        while(left<right){
            totalSum +=gcd(prefixGrid[left],prefixGrid[right]);
            left++;
            right--;

        }
        return totalSum;
    }
};