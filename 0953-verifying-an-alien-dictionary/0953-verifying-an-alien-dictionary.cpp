class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int alien_order[26];
        for(int i=0;i<26;i++){
            alien_order[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string word1=words[i];
            string word2=words[i+1];
            bool diffFound=false;
            int minLen=min(word1.length(),word2.length());
            for(int j=0;j<minLen;j++){
                if(word1[j] !=word2[j]){
                    if(alien_order[word1[j]-'a'] > alien_order[word2[j]-'a']){
                        return false;
                    }
                    diffFound=true;
                    break;
                }
            }
            if(!diffFound && word1.length()>word2.length()){
                return false;
            }


        }
        return true;
    }
};