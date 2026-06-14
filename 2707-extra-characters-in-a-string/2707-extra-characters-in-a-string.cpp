class Solution {
public:
     int dp[51];
     int solve(int i,string& s,unordered_set<string>& dictSet ){
        if(i>=s.length()) return 0;
        if(dp[i] !=-1) return dp[i];
        int minExtra=1+solve(i+1,s,dictSet);
        string current_word="";
        for(int j=i;j<s.length();j++){
            current_word +=s[j];
            if(dictSet.count(current_word)){
                int extra=solve(j+1,s,dictSet);
                minExtra=min(minExtra,extra);

            }

        }
        return dp[i]=minExtra;

     }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>dictSet(dictionary.begin(),dictionary.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,dictSet);
    }
};