class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
      
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }
            srow++;

          
            for (int i = srow; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }
            ecol--;

            
            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--) {
                    ans.push_back(mat[erow][j]);
                }
                erow--;
            }

            
            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--) {
                    ans.push_back(mat[i][scol]);
                }
                scol++;
            }
        }

        return ans;
    }
};