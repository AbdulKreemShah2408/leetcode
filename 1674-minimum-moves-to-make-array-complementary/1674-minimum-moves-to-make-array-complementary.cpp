#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
       
       
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

           
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            
            int min_val = min(a, b) + 1;
            int max_val = max(a, b) + limit;
            diff[min_val] -= 1;
            diff[max_val + 1] += 1;

           
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = n; 
        int current_moves = 0;
        
        for (int s = 2; s <= 2 * limit; ++s) {
            current_moves += diff[s];
            ans = min(ans, current_moves);
        }

        return ans;
    }
};