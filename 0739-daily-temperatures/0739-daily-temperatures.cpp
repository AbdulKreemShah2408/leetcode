class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>s;
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            while(!s.empty() && temperatures[i]> temperatures[s.top()]){
                res[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};