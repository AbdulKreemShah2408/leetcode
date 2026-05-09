#include <vector>
#include <map>
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize !=0) return false;
        map<int,int>counts;
        for(int card:hand){
            counts[card]++;
        }
        for(auto it=counts.begin(); it !=counts.end();++it){
            int currentCard=it->first;
            int count=it->second;
            if(count>0){
                for(int i=0;i<groupSize;++i){
                    int nextCard=currentCard+i;
                    if(counts[nextCard]<count){
                        return false;
                    }
                    counts[nextCard] -=count;
                }
            }
        }
        return true;
    }
};