class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trust_score(n+1,0);
        for(auto& relation:trust){
            int a=relation[0];
            int b=relation[1];
            trust_score[a]--;
            trust_score[b]++;
        }
        for(int i=1;i<=n;i++){
            if(trust_score[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};