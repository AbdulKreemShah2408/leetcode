class Solution {
public:
  bool isVowels(char c){
    c=tolower(c);
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';

  }
    string reverseVowels(string s) {
      int i=0, j=s.size()-1;
      while(i<j){
       if(isVowels(s[i]) && isVowels(s[j])){
        swap(s[i],s[j]);
        i++;
        j--;
       }
       else if(!isVowels(s[i])){
        i++;
       }
       else if(!isVowels(s[j])){
        j--;
       }
      }
      return s;
    }
};