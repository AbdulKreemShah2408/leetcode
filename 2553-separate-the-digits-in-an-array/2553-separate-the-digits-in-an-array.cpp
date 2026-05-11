class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>result;
        for(int val:nums){
            string s=to_string(val);
            for(char c:s){
                result.push_back(c-'0');
            }
        }
        return result;
    }
};