class Solution {
public:
    int mySqrt(int x) {
        if(x<0) return -1;
        if(x==0) return 0;
        int num=sqrt(x);
        return num;
    }
};