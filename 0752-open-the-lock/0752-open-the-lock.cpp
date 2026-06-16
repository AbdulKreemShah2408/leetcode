class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
       unordered_set<string>visited(deadends.begin(),deadends.end());
       if(visited.count("0000")) return -1;
       queue<string>q;
       q.push("0000");
       visited.insert("0000");
       int turns=0;
       while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            string curr=q.front();
            q.pop();
            if(curr==target) return turns;
            for(int j=0;j<4;j++){
                char original_char=curr[j];
                char up=(original_char=='9') ? '0':original_char+1;
                curr[j]=up;
                if(!visited.count(curr)){
                    visited.insert(curr);
                    q.push(curr);

                }
                char down=(original_char=='0') ?'9' :original_char-1;
                curr[j]=down;
                if(!visited.count(curr)){
                    visited.insert(curr);
                    q.push(curr);

                }
                curr[j]=original_char;
            }
        }
        turns++;
       } 
       return -1;
    }
};