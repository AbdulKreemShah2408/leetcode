#include <algorithm>
#include <map>
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sortedArr=arr;
        sort(sortedArr.begin(),sortedArr.end());
        auto it=unique(sortedArr.begin(),sortedArr.end());
        sortedArr.erase(it,sortedArr.end());
        map<int,int>rankMap;
        for(int i=0;i<sortedArr.size();++i){
          rankMap[sortedArr[i]]=i+1;
        }
        for(int i=0;i<arr.size();++i){
            arr[i]=rankMap[arr[i]];
        }
        return arr;
    }
};