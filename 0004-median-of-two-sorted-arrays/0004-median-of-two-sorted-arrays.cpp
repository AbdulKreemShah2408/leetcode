class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if(nums1.size()>nums2.size()){
        return findMedianSortedArrays(nums2,nums1);
       }
       int m=nums1.size();
       int n=nums2.size();
       int low=0, high=m;
       while(low<=high){
        int partionX=low+(high-low)/2;
        int partionY=(m+n+1)/2-partionX;
        int L1=(partionX==0) ? INT_MIN :nums1[partionX-1];
        int R1=(partionX==m) ? INT_MAX :nums1[partionX];
        int L2=(partionY==0) ? INT_MIN :nums2[partionY-1];
        int R2=(partionY==n) ? INT_MAX :nums2[partionY];
        if(L1<=R2 && L2<=R1){
        if((m+n)%2==0){
            return (max(L1,L2)+min(R1,R2))/2.0;
        }else{
            return max(L1,L2);
        }
        }
        else if(L1>R2){
            high=partionX-1;
        }else{
            low=partionX+1;
        }
       }
       return 0.0;
    }
};