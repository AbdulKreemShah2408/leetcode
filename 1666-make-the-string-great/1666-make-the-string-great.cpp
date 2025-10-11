class Solution {
public:
    string makeGood(string s) {
        stack<char>s1;
        for(char c:s){
            if(!s1.empty() && abs(s1.top()-c)==32){
             s1.pop();
            }
            else{
                s1.push(c);
            }
        }
        string result="";
        while(!s1.empty()){
            result +=s1.top();
            s1.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};