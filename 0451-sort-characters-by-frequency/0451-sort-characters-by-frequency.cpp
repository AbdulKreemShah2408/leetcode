class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int>freq;
        for(auto x:s){
            freq[x]++;
        }
        sort(s.begin(),s.end(),[&](char a, char b){
        if(freq[a]==freq[b])
        return a<b;
        return freq[a]>freq[b];
        });
         return s;
    
    }
};