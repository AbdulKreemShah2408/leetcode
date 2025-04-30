class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int n=nums.size();
       int count=0;
       for(int i=0;i<n;i++){
        int num=nums[i];
         int digit_count=0;
        while(num>0){
            num /= 10;
            digit_count++;
           
        }
         if(digit_count%2==0){
                 count++;
            }
       }

        return count;
       }
};