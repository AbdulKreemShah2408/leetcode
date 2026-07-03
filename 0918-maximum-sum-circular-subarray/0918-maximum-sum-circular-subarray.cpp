class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0;
        int max_sum=nums[0];
        int current_max=0;
        int min_sum=nums[0];
        int current_min=0;
        for(int x:nums){
            total_sum +=x;
            current_max=max(x,current_max+x);
            max_sum=max(max_sum,current_max);
             current_min = min(x, current_min + x);
            min_sum = min(min_sum, current_min);
        }
        if (total_sum == min_sum) {
            return max_sum;
        }
        return max(max_sum, total_sum - min_sum);
    }
};