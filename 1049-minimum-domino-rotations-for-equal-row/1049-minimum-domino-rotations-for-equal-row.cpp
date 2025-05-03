class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int rotationsA = 0, rotationsB = 0;
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) return -1; 
            else if (tops[i] != x) rotationsA++;  
            else if (bottoms[i] != x) rotationsB++;  
        }
        return min(rotationsA, rotationsB);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1) return result;
        return check(bottoms[0], tops, bottoms);
    }
};
