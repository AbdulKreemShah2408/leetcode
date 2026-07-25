class Solution {
public:
    int maxProduct(int n) {
       vector<int>digits;
       while(n>0){
        digits.push_back(n%10);
        n /=10;
       }
       int max_prod=0;
       int size=digits.size();
       for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int current_prod=digits[i]*digits[j];
            max_prod=max(max_prod,current_prod);
        }
       }
       return max_prod;
    }
};