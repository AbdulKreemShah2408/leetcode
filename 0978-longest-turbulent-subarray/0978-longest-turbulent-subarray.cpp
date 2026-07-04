class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n<2) return n;
        int max_len=1;
        int current_len=1;
        int back_sign=0;
        for(int i=0;i<n-1;i++){
            int current_sign=0;
            if(arr[i]<arr[i+1]){
                current_sign=-1;
            }else if(arr[i]>arr[i+1]){
                current_sign=1;
            }else{
                current_sign=0;
            }
            if(current_sign==0){
                current_len=1;
            }else if(current_sign==-back_sign){
                current_len +=1;
            }else{
                current_len=2;
            }
            back_sign=current_sign;
            max_len=max(max_len,current_len);
        }
        return max_len;
    }
};