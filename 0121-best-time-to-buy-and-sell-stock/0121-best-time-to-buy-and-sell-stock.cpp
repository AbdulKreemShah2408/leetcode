class Solution {
public:
    int maxProfit(vector<int>& price) {
        int maxProfit=0, bestBuy=price[0];
        for(int i=0;i<price.size();i++){
            if(price[i]>bestBuy){
                maxProfit=max(maxProfit,price[i]-bestBuy);
            }
            bestBuy=min(bestBuy,price[i]);
        }
        return maxProfit;
    }
};