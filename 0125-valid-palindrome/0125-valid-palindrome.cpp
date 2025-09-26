class Solution {
public:
   bool isAlphaNum(char c){
if((c>='0' && c<='9') || (tolower(c)>='a' && tolower(c)<='z')){
        return true;
    }
    return false;
   }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(!isAlphaNum(s[i])){
                i++;
                continue;
            }
             if(!isAlphaNum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};