class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val=0;
        for(int x:nums) max_val=max(max_val,x);
        vector<int>freq(max_val+1,0);
        for(int x:nums) freq[x]++;
        vector<long long>count_multiples(max_val+1,0);
        for(int g=1;g<=max_val;++g){
            for(int m=g;m<=max_val; m+=g){
                count_multiples[g] +=freq[m];
            }
        }
        vector<long long>exact_gcd(max_val+1,0);
        for(int g=max_val;g>=1;--g){
            long long c=count_multiples[g];
            exact_gcd[g] =c*(c-1)/2;
            for(int m=2*g;m<=max_val; m+=g){
                exact_gcd[g] -=exact_gcd[m];
            }

        }
        vector<long long>prefix_gcd(max_val+1,0);
        for(int g=1;g<=max_val;++g){
            prefix_gcd[g]=prefix_gcd[g-1]+exact_gcd[g];
        }
        vector<int> results;
        for (long long q : queries) {
            auto it = upper_bound(prefix_gcd.begin(), prefix_gcd.end(), q);
            results.push_back(distance(prefix_gcd.begin(), it));
        }

        return results;
    }
};