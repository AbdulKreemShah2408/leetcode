class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index=m+n-1, i=m-1, j=n-1;
        while(i>=0 && j>=0){
            if(A[i]>=B[j]){
                A[index]=A[i];
                index--, i--;
            }else{
                A[index]=B[j];
                index--,j--;
            }
        }
        while(j>=0){
            A[index]=B[j];
            index--,j--;
        }
    }
};