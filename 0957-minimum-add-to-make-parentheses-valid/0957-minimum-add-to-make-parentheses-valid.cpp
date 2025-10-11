class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>s1;
        for(char ch:s){
            if(ch=='(' ){
                s1.push(ch);
            }else{
                if(!s1.empty()  && ch==')' && s1.top()=='('){
                    s1.pop();
                }
                else{
                    s1.push(')');
                }
                
            }
        }
        return s1.size();
    }
};