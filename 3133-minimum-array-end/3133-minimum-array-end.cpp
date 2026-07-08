class Solution {
public:
    long long minEnd(int n, int x) {
        
        long long result = x; 
        long long remaining = n - 1;
        
        long long position = 1;

        while (remaining > 0) {
            
            if ((x & position) == 0) {
               
                if (remaining & 1) {
                    result |= position;
                }
               
                remaining >>= 1;
            }
           
            position <<= 1;
        }
        
        return result;
    }
};