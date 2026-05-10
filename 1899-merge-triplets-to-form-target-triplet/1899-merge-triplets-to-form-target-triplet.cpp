class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundX=false, foundY=false, foundZ=false;
        for(auto& t:triplets){
            if(t[0]<=target[0] && t[1]<=target[1] && t[2]<=target[2]){
                if(t[0]==target[0]) foundX=true;
                if(t[1]==target[1]) foundY=true;
                if(t[2]==target[2]) foundZ=true;
            }
            if(foundX && foundY && foundZ) return true;
        }
        return foundX && foundY && foundZ;
    }
};
