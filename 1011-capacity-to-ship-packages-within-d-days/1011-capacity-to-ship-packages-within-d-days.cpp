class Solution {
public:
    bool canShip(vector<int>& weights,int capacity,int days){
        int daysCount=1;
        int currentWeight=0;
        for(int w:weights){
            if(currentWeight+w>capacity){
                daysCount++;
                currentWeight =w;
            }else{
                currentWeight +=w;
            }
        }
        return daysCount<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(int w:weights){
            low=max(low,w);
            high +=w;
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canShip(weights,mid,days)){
                ans=mid;
                high=mid-1;

            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};