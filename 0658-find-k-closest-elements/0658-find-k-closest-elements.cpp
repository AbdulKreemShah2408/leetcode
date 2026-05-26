class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int left=0;
       int right=arr.size()-1;
       while(right-left>=k){
       int dist_left=abs(arr[left]-x);
       int dist_right=abs(arr[right]-x);
       if(dist_left>dist_right){
        left++;
       }else{
        right--;
       }
       } 
       return vector<int>(arr.begin()+left,arr.begin()+right+1);
    }
};