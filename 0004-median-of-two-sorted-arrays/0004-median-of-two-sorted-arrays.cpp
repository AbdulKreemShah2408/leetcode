class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        for(int x:nums1){
            merged.push_back(x);
        }
        for(int x:nums2){
            merged.push_back(x);
        }
        sort(merged.begin(),merged.end());
        int n=merged.size();
        if(n%2==1){
            return merged[n/2];
        }
        return (merged[n/2]+merged[n/2-1])/2.0;
    }
};