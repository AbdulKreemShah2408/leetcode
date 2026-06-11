class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>projects;
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});

        }
        sort(projects.begin(),projects.end());
        priority_queue<int>maxProfitHeap;
        int i=0;
        for(int j=0;j<k;j++){
            while(i<n && projects[i].first<=w){
                maxProfitHeap.push(projects[i].second);
                i++;
            }
            if(maxProfitHeap.empty()){
                break;

            }
            w+=maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        return w;
    }
};