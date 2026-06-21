class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>freq(100001,0);
        for(int c:costs){
            freq[c]++;
        }
        int ice_cream_bought=0;
        for(int price=1;price<=100000;price++){
            if(freq[price]==0) continue;
            if(coins<price){
                break;
            }
            long long count_to_buy=min((long long)freq[price],(long long)(coins/price));
            ice_cream_bought +=count_to_buy;
            coins -=count_to_buy*price;
        }
        return ice_cream_bought;
    }
};