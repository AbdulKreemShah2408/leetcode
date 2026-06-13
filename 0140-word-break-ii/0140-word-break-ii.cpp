class Solution {
public:
    vector<string>result;
    unordered_set<string>wordSet;
    void solve(int index,string& s,string currentSentence){
        if(index==s.length()){
            result.push_back(currentSentence);
            return;
        }
        string temp="";
        for(int i=index;i<s.length();i++){
            temp +=s[i];
            if(wordSet.count(temp)){
                string nextSentence=currentSentence.empty() ? temp: currentSentence+ " " +temp;
                solve(i+1,s,nextSentence);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict){
            wordSet.insert(word);
        }
        solve(0,s,"");
        return result;
    }
};