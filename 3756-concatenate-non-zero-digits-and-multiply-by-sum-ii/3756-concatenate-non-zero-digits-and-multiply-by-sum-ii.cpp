class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        vector<long long> power10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        vector<long long> prefX(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);
        vector<int> nonZeroCount(m + 1, 0);

        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                prefX[i + 1] = (prefX[i] * 10 + digit) % MOD;
                nonZeroCount[i + 1] = nonZeroCount[i] + 1;
            } else {
                prefX[i + 1] = prefX[i];
                nonZeroCount[i + 1] = nonZeroCount[i];
            }
            prefSum[i + 1] = prefSum[i] + digit;
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int k = nonZeroCount[r + 1] - nonZeroCount[l];
            if (k == 0) {
                answer.push_back(0);
                continue;
            }

            long long x = (prefX[r + 1] - (prefX[l] * power10[k]) % MOD + MOD) % MOD;
            long long sum = prefSum[r + 1] - prefSum[l];
            long long final_ans = (x * sum) % MOD;
            
            answer.push_back(final_ans);
        }

        return answer;
    }
};