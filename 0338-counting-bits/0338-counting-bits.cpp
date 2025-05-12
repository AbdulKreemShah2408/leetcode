class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>count;
        for(int i=0;i<=n;i++){
            int x=i;
            int bitcount=0;
            while(x>0){
            bitcount +=(x&1);
            x>>=1;
            }
            count.push_back(bitcount);
        }
        return count;
    }
};