class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n = s.size();
        vector<char> arr(s.begin(), s.end());
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (arr[j] == '.') continue;
            if (arr[i] == arr[j]) {
                for (int k = i + 1; k < j; k++) {
                    arr[k] = arr[i];
                }
            } else if (arr[i] == 'R' && arr[j] == 'L') {
                int left = i + 1;
                int right = j - 1;
                while (left < right) {
                    arr[left++] = 'R';
                    arr[right--] = 'L';
                }
            }
            i = j; 
        }
        return string(arr.begin() + 1, arr.end() - 1);
    }
};
