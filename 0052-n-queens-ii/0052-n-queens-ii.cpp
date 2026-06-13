class Solution {
public:
    int totalSolutions=0;
    void solve(int row,int n,vector<bool>&cols,vector<bool>& diag1,vector<bool>& diag2){
       if(row==n){ 
       totalSolutions++;
       return;
       }
       for(int col=0;col<n;col++){
        int d1=row-col+n;
        int d2=row+col;
        if(!cols[col] && !diag1[d1] && !diag2[d2]){
            cols[col]=true;
            diag1[d1]=true;
            diag2[d2]=true;
            solve(row+1,n,cols,diag1,diag2);
            cols[col]=false;
            diag1[d1]=false;
            diag2[d2]=false;

            
        }
       }
    }
    int totalNQueens(int n) {
        vector<bool>cols(n,false);
        vector<bool>diag1(2*n,false);
        vector<bool>diag2(2*n,false);
        solve(0,n,cols,diag1,diag2);
        return totalSolutions;
    }
};