class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>>sortedTasks;
        for(int i=0;i<n;i++){
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedTasks.begin(),sortedTasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int>result;
        long long currentTime=0;
        int taskIndex=0;
        while(taskIndex<n || !minHeap.empty()){
            if(minHeap.empty() && currentTime<sortedTasks[taskIndex][0]){
            currentTime=sortedTasks[taskIndex][0];
            }
            while(taskIndex<n && sortedTasks[taskIndex][0]<=currentTime){
                minHeap.push({sortedTasks[taskIndex][1],sortedTasks[taskIndex][2]});
                taskIndex++;
            }
            auto [processingTime,index]=minHeap.top();
            minHeap.pop();
            result.push_back(index);
            currentTime +=processingTime;
        }
        return result;
    }
};