class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>m;
        int result=0;
        for(int i=0;i<dominoes.size();i++){
            int a=dominoes[i][0];
            int b=dominoes[i][1];
            int key=min(a,b)*10 + max(a,b);
             result += m[key];
            m[key]++;
        }
        return result;
    }
};