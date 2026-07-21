class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int totalOnes=0;
        int maxZeroSum=0;
        int prevZeroLen=INT_MIN;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && s[j]==s[i]){
                j++;
            }
            int len=j-i;
            if(s[i]=='1'){
                totalOnes +=len;
            }else{
                maxZeroSum=max(maxZeroSum,prevZeroLen+len);
                prevZeroLen=len;
            }
            i=j;
        }
        return totalOnes+maxZeroSum;
    }
};