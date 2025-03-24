#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp = height.size() - 1;
        while (lp < rp) {
            int w = rp - lp;
            int ht = std::min(height[lp], height[rp]);
            int currWater = w * ht;
            maxWater = std::max(maxWater, currWater);

            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        return maxWater;
    }
};