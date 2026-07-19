class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>lastIndex;
        for(int i=0;i<s.length();i++){
            lastIndex[s[i]]=i;
        }
        vector<char>stack;
        unordered_set<char>seen;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(seen.find(c) !=seen.end()){
                continue;
            }
            while(!stack.empty() && c<stack.back() && lastIndex[stack.back()]>i){
                seen.erase(stack.back());
                stack.pop_back();

            }
            stack.push_back(c);
            seen.insert(c);
        }
        string result(stack.begin(),stack.end());
        return result;
    }
};