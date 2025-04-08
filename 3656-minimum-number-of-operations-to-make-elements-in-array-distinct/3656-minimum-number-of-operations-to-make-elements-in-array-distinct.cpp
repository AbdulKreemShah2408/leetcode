class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int numOpreations=0;
        
        while(true){
           unordered_set<int>freq;
            bool isDuplicate=false;
            for(int num:nums){
             if(freq.find(num)!=freq.end()){
                isDuplicate=true;
                break;
            }
            freq.insert(num);
            }
            if(!isDuplicate) break;
            nums.erase(nums.begin(),nums.begin()+min(3,(int)nums.size()));

          numOpreations++;
           
        }
        return numOpreations;
    }
};