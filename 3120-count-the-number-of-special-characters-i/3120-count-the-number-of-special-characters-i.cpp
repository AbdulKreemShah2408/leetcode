class Solution {
public:
    int numberOfSpecialChars(string word) {
      vector<bool>hasLower(26,false);
      vector<bool>hasUpper(26,false);
      for(char ch:word){
        if(ch>='a' && ch<='z'){
            hasLower[ch-'a']=true;
        }else if(ch>='A' && ch<='Z'){
            hasUpper[ch-'A']=true;
        }
      }
      int count=0;
      for(int i=0;i<26;i++){
        if(hasLower[i] && hasUpper[i]){
            count++;

        }
      }
      return count;
    }
};