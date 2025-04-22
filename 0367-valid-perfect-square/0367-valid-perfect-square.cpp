class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<0) return false;
       long long left=1, right=num;
       while(left<=right){
        long long mid=left+(right-left)/2;
        long long saqure=mid*mid;
        if(saqure==num){
            return true;
        }
        else if(saqure<num){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
       }
       return false;
    }
};