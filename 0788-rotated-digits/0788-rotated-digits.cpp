class Solution {
public:
   bool isGoodNumber(int num){
     bool hasChangedDigit=false;
     while(num>0){
        int digit=num%10;
        if(digit==3 || digit==4 || digit==7){
            return false;
        }
        if(digit==2 || digit==5 || digit==6 || digit==9){
             hasChangedDigit=true;
        }
        num /=10;
     }
     return hasChangedDigit;
   }
    int rotatedDigits(int n) {
        int goodNumberCount=0;
        for(int i=1;i<=n;i++){
            if(isGoodNumber(i)){
                goodNumberCount++;
            }
        }
      return goodNumberCount;
    }
};