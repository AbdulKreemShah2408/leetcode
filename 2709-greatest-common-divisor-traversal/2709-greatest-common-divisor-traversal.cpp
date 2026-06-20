class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int max_element=0;
        for(int num:nums){
            if(num==1) return false;
            max_element=max(max_element,num);
        }
        DSU dsu(max_element+1);
        vector<int>prime_to_num(max_element+1,-1);
        for(int num:nums){
            int temp=num;
            for(int factor=2;factor*factor<=temp;factor++){
                if(temp%factor==0){
                    if(prime_to_num[factor] !=-1){
                        dsu.unite(num,prime_to_num[factor]);

                    }else{
                        prime_to_num[factor]=num;
                    }
                    while(temp%factor==0){
                        temp /=factor;
                    }
                }
            }
            if(temp>1){
                if(prime_to_num[temp] !=-1){
                    dsu.unite(num,prime_to_num[temp]);
                }else{
                    prime_to_num[temp]=num;
                }
            }
        }
        int first_num_root=dsu.find(nums[0]);
        for(int i=0;i<n;i++){
            if(dsu.find(nums[i]) !=first_num_root){
                return false;
            }
        }
        return true;
    }
};