class Solution {
    private:
     int totalSum=0;
     void getSubsetsXOR(int index,int currentXOR,vector<int>& nums){
        if(index==nums.size()){
            totalSum +=currentXOR;
            return;
        }
        getSubsetsXOR(index+1,currentXOR^nums[index],nums);
        getSubsetsXOR(index+1,currentXOR,nums);
     }
public:
   
    int subsetXORSum(vector<int>& nums) {
         totalSum=0;
        getSubsetsXOR(0,0,nums);
        return totalSum;
    }
};