class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>R,D;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R') R.push(i);
            else D.push(i);
        }
        while(!R.empty() && !D.empty() ){
            int r=R.front();
            int d=D.front();
            R.pop();
            D.pop();
            if(r<d){
                R.push(r+n);
            }
            else{
                D.push(d+n);
            }
        }
        return R.empty() ? "Dire" :"Radiant";
    }
};