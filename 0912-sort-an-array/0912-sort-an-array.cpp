class Solution {
public:
    void merge(vector<int>& nums,int start,int mid,int end){
        vector<int>temp;
        int left=start;
        int right=mid+1;
        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
    }
    void mergeSort(vector<int>& nums,int start,int end){
        if(start>=end) return ;
        int mid=start+(end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
     mergeSort(nums,0,nums.size()-1);
     return nums;
      

    }
    
};