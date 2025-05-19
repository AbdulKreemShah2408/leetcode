class Solution {
public:
    string triangleType(vector<int>& nums) {
        string result;
       int a=nums[0];
       int b=nums[1];
       int c=nums[2];
       if (a + b <= c || a + c <= b || b + c <= a) {
         return "none";
        }
       if(a==b && b==c){
       result="equilateral";
       }
       else if(a==b || b==c || a==c){
        result="isosceles";
       }
       else {
        result="scalene";
       }
       return result;
    }
};