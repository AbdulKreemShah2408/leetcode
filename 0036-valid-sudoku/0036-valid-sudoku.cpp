class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]={false};
        bool cols[9][9]={false};
        bool boxes[9][9]={false};
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char ch=board[r][c];
                if(ch== '.') continue;
                int val= ch - '1';
                int b=(r/3)*3 +(c/3);
                if(rows[r][val] || cols[c][val] || boxes[b][val]){
                    return false;
                }
                rows[r][val]=cols[c][val]=boxes[b][val]=true;
            }
        }
        return true;
    }
};