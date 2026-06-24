#include <vector>
#include <iostream>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    int M;


    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        vector<vector<long long>> C(M, vector<long long>(M, 0));
        for (int i = 0; i < M; i++) {
            for (int k = 0; k < M; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < M; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }


    vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
        vector<vector<long long>> res(M, vector<long long>(M, 0));
        for (int i = 0; i < M; i++) res[i][i] = 1; 
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int K = r - l + 1;
        if (n == 1) return K; 
        
        M = 2 * K;
        
      
        vector<long long> init(M, 0);
        for (int v = 1; v <= K; v++) {
            for (int u = 1; u <= K; u++) {
                if (v < u) init[u - 1]++;        
                if (v > u) init[K + u - 1]++;   
            }
        }
        
        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < M; i++) ans = (ans + init[i]) % MOD;
            return ans;
        }

      
        vector<vector<long long>> T(M, vector<long long>(M, 0));
        for (int u = 1; u <= K; u++) {
           
            for (int w = 1; w < u; w++) {
                T[u - 1][K + w - 1] = 1;
            }
       
            for (int w = u + 1; w <= K; w++) {
                T[K + u - 1][w - 1] = 1;
            }
        }

       
        vector<vector<long long>> T_pow = power(T, n - 2);

        long long total_arrays = 0;
        for (int j = 0; j < M; j++) {
            long long current_state_ways = 0;
            for (int i = 0; i < M; i++) {
                current_state_ways = (current_state_ways + init[i] * T_pow[i][j]) % MOD;
            }
            total_arrays = (total_arrays + current_state_ways) % MOD;
        }

        return total_arrays;
    }
};