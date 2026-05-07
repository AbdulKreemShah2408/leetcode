class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachAble = 0;
        for (int i = 0; i < n; i++) {
            if (reachAble < i) {
                return false;
            }
            reachAble = max(reachAble, i + nums[i]);
        }
        return true;
    }
};