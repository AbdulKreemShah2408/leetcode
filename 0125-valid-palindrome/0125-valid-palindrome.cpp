class Solution {
public:
  bool isAlphaNumeric(char c){
    if((c>='0' && c<='9') || (tolower(c)>='a' && tolower(c)<='z') ){
        return true;
    }
    return false;
  }
    bool isPalindrome(string s) {
      int n=s.size();
      int i=0, j=n-1;
      while(i<j){
       if(!isAlphaNumeric(s[i])){
        i++;
        continue;
       }
       if(!isAlphaNumeric(s[j])){
        j--;
        continue;
       }
       if(tolower(s[i]) != tolower(s[j]) ){
        return false;
       }
       i++;
       j--;
      }
      return true;
    }
};