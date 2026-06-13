class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> countT, window;
        for (char c : t)
            countT[c]++;
        int have = 0;
        int need = countT.size();
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[s[right]]++;
            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }
            while (have == need) {
                if ((right - left + 1) < resLen) {
                    resLen = right - left + 1;
                    res = {left, right};
                }
                char leftChar = s[left];
                window[leftChar]--;
                if (countT.count(leftChar) &&
                    window[leftChar] < countT[leftChar]) {
                    have--;
                }
                left++;
            }
        }
        if(resLen==INT_MAX) return "";
        return s.substr(res.first,resLen);
    }
};