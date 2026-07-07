class Solution {
public:
    long long sumAndMultiply(int n) {
       if(n<=0) return 0;
       long long x=0;
       long long sum = 0;
       long long product = 1;
       long long multiplier=1;
       while(n>0){
        int digit=n%10;
        if(digit !=0){
            sum +=digit;
            x=x+(digit*multiplier);
            multiplier *=10;
        }
        n /=10;
       }
       return x*sum;
    }
};