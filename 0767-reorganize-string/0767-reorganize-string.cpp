class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                if(freq[i]>(n+1)/2) return "";
                maxHeap.push({freq[i],(char)(i+'a')});

                
            }
        }

        string result="";
        while(maxHeap.size()>=2){
            auto [freq1,char1]=maxHeap.top();maxHeap.pop();
            auto [freq2,char2]=maxHeap.top();maxHeap.pop();

            result +=char1;
            result +=char2;
            if(--freq1>0) maxHeap.push({freq1,char1});
            if(--freq2>0)  maxHeap.push({freq2,char2});
        }
        if(!maxHeap.empty()){
            auto [freqLeft,charLeft]=maxHeap.top();
            result +=charLeft;
        }
        return result;
    }
};