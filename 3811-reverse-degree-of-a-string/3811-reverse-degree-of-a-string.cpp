class Solution {
public:
    int reverseDegree(string s) {
        int total=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
              int revValue=26-(ch-'a');
             int product =revValue * (i+1);
              total +=product;
        }
        return total;
     
    }
};