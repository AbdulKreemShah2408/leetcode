class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string ans="";
       for(string word:words){
        int wordSum=0;
        for(char ch:word){
            wordSum +=weights[ch-'a'];
        }
        int rem=wordSum%26;
        char mappedChar='z'-rem;
        ans +=mappedChar;
       }
       return ans;
    }
};