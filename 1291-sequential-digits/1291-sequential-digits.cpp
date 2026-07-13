class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        string digits="123456789";
        for(int len=2;len<=9;++len){
            for(int i=0;i<=9-len;++i){
              string sub=digits.substr(i,len);
              int num=stoi(sub);
              if(num>=low && num<=high){
                result.push_back(num);
              }
            }
        }
        sort(result.begin(),result.end());
        return result;

    }
};