class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,bool>m;
        for(int num:nums){
            m[num]=true;
        }
        for(int i=0;i<=n;i++){
        if(m.find(i) == m.end()){
            return i;
        }
        }
        return -1;
    }
};