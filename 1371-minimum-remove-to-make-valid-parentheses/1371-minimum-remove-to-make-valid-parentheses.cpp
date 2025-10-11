class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>s1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else if(s[i]==')'){
                if(!s1.empty()  && s[s1.top()]=='('){
                    s1.pop();
                }
                else{
                    s1.push(i);
                }
              

            }
          
        }
        unordered_set<int>invalid;
        while(!s1.empty()){
            invalid.insert(s1.top());
            s1.pop();
        }
          string result="";
            for(int i=0;i<s.size();i++){
                if(invalid.find(i)==invalid.end()){
                result +=s[i];
                }
            }
            return result;

    }
};