class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0;
        
        for (int i = 0; i < tickets.size(); i++) {
           
            if (i <= k) {
                totalTime += min(tickets[i], tickets[k]);
            } 
           
            else {
                totalTime += min(tickets[i], tickets[k] - 1);
            }
        }
        
        return totalTime;
    }
};