class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        if(s[n-1]=='1') return false;
        queue<int>q;
        q.push(0);
        int far=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(i==n-1) return true;
            int start=max(i+minJump,far+1);
            int end=min(i+maxJump,n-1);
            for(int j=start;j<=end;j++){
                if(s[j]=='0'){
                    q.push(j);
                }
            }
            far=max(far,end);
        }
        return false;
    }
};