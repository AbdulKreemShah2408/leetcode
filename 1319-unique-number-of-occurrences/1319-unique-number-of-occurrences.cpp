class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
         for(auto x:arr){
            freq[x]++;
         }

         unordered_set<int>seenCount;
         for(auto &p:freq){
            int count=p.second;
            if(!seenCount.insert(count).second) return false;
         }
         return true;
    }
};