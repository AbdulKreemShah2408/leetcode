class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=0;
        int n=nums.size();
        while(i<n && j<n){
            if(nums[i]==val){
                i++;
                
            }else{
             nums[j]=nums[i];
             i++;
             j++;
            }
        }
        return j;
    }
};