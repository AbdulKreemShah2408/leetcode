class Solution {
public:
   void solve(vector<vector<int>>& ans,vector<int>& cand,int target,int sum,vector<int>& temp,int index){
    if(sum==target){
        ans.push_back(temp);
        return ;
    }
    if(sum>target || index>=cand.size()){
        return ;
    }
    temp.push_back(cand[index]);
    solve(ans,cand,target,sum+cand[index],temp,index);
    temp.pop_back();
    solve(ans,cand,target,sum,temp,index+1);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates , int target) {
     vector<vector<int>>ans;
     vector<int>temp;
     solve(ans,candidates,target,0,temp,0);
     return ans;
    }
};