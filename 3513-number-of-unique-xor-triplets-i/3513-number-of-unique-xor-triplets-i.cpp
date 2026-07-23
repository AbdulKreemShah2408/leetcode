class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n=nums.size();
       if(n<=2) return n;
       int max_val=0;
       for(int x:nums){
        max_val=max(max_val,x);
       }
       int msb=0;
       while((1<<msb)<=max_val){
        msb++;
       }
       return 1<<msb;
    }
};