class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>freq;
        for(char c:chars){
            freq[c]++;
        }

        int total=0;
        for(string word:words){
            unordered_map<char,int>temp;
            bool good=true;
           for(char c:word){
            temp[c]++;
            if(temp[c]>freq[c]){
                good=false;
                break;
            }
           }
         if(good) total+=word.size();
        }
        return total;
    }
};