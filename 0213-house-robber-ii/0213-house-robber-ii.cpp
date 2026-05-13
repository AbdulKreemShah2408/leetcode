class Solution {
public:
    int simpleRob(vector<int>& nums,int start,int end){
        int prev2=0;
        int prev1=0;
        for(int i=start;i<=end;i++){
            int current=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=current;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int option1=simpleRob(nums,0,n-2);
        int option2=simpleRob(nums,1,n-1);
        return max(option1,option2);
    }
};
