class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int totalPushes=0;
        for(int i=0;i<n;i++){
            int multiplier=(i/8)+1;
            totalPushes +=multiplier;
        }
        return totalPushes;
    }
};