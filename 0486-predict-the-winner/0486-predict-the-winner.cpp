class Solution {
    private:
    int memo[21][21];
    int solve(vector<int>&nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        if(memo[left][right] !=-1){
         return memo[left][right];
        }
        int takeLeft=nums[left]-solve(nums,left+1,right);
        int takeRight=nums[right]-solve(nums,left,right-1);
        return memo[left][right]=max(takeLeft,takeRight);
    }

public:
    
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,n-1) >=0;
    }
};