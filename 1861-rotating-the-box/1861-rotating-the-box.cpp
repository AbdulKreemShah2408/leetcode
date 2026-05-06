class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        for(int i=0;i<m;i++){
            int empty_spot=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    empty_spot=j-1;

                }else if(boxGrid[i][j]=='#'){
                    char temp=boxGrid[i][j];
                    boxGrid[i][j]=boxGrid[i][empty_spot];
                    boxGrid[i][empty_spot]=temp;
                    empty_spot--;
                }
            }
        }
        vector<vector<char>>rotatedBox(n,vector<char>(m));
        for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
            rotatedBox[j][m-1-i]=boxGrid[i][j];
         }
        }
        return rotatedBox;
    }
};