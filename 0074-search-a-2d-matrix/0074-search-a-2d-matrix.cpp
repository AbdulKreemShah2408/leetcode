class Solution {
public:
  bool searchRow(vector<vector<int>>& mat, int tar,int row){
     int n=mat[0].size();
     int start=0, end=n-1;
     while(start<=end){
        int mid=start+(end-start)/2;
        if(tar==mat[row][mid]){
            return true;
        }
        else if(tar>mat[row][mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
     }
     return false;
  }
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
       int m=mat.size(),  n=mat[0].size();
       int startRow=0;
        int endRow=m-1;
       while(startRow<=endRow){
       int mid=startRow+(endRow-startRow)/2;
       if(tar>=mat[mid][0] && tar<=mat[mid][n-1]){
        return searchRow(mat,tar,mid);
       }
       else if(tar>mat[mid][n-1]){
        startRow=mid+1;
       }
       else {
        endRow=mid-1;
       }
       }
       return false;
      
       
    }
};