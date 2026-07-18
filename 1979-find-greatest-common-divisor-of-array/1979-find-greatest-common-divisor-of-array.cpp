class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [min_it,max_it]=minmax_element(nums.begin(),nums.end());
        int min_val=*min_it;
        int max_val=*max_it;
        return gcd(min_val,max_val);
    }
};