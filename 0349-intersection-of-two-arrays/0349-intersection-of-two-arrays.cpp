class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int>s;
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
       int start=0, end=0;
       while(start<nums1.size() && end<nums2.size()){
        if(nums1[start]==nums2[end]){
            s.insert(nums1[start]);
            start++;
            end++;
        }
        else if(nums1[start]<nums2[end]){
            start++;
        }
        else{
            end++;
        }
        
       }
       vector<int>ans (s.begin(),s.end());
       return ans;
    }
};