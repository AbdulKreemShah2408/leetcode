class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLetter=0;
        int left=0;
        int right=0;
        int maxLength=0;
        unordered_map<char,int>mp;
        while(right<s.size()){
            mp[s[right]]++;
            maxLetter=max(mp[s[right]],maxLetter);
            if(right-left+1-maxLetter>k){
                mp[s[left]]--;
                left++;
            }else{
                maxLength=max(maxLength,right-left+1);
                
            }
           right++;
        }
        return maxLength;
    }
};