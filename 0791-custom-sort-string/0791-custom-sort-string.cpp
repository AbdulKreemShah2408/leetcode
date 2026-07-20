class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>count;
        for(char c:s){
            count[c]++;

        }
        string result="";
        for(char c:order){
            if(count.find(c) !=count.end()){
                result.append(count[c],c);
                count.erase(c);
            }

        }
        for(auto const& [key,val]:count){
            result.append(val,key);
        }
        return result;
    }
};