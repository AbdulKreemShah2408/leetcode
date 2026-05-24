class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        unordered_map<int, int> m;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if (prefixSum == k) count++;
            int val = prefixSum - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }
            m[prefixSum]++;
        }

        return count;
    }
};