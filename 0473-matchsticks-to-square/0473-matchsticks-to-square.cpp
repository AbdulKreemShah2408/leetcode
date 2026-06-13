class Solution {
public:
    bool canFormSaqure(int index,vector<int>&matchsticks,vector<int>&sides,int target){
        if(index==matchsticks.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            if(sides[i]+matchsticks[index]<=target){
                sides[i] +=matchsticks[index];
                if(canFormSaqure(index+1,matchsticks,sides,target)){
                    return true;
                }
                sides[i] -=matchsticks[index];
            }
            if(sides[i]==0)  break;
            if(i>0 && sides[i]==sides[i-1]) continue;
        }
        return false;

    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()<4) return false;
        int totalSum=0;
        for(int len:matchsticks){
            totalSum +=len;
        }
        if(totalSum%4 !=0) return false;
        int target=totalSum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0]>target) return false;
        vector<int>sides(4,0);
        return canFormSaqure(0,matchsticks,sides,target);


    }
};