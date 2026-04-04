class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>counts;
        for(char t:tasks) counts[t]++;
        priority_queue<int>pq;
        for(auto const & [task,freq]:counts){
            pq.push(freq);
        }
        int time=0;
        queue<pair<int,int>>waitQueue;
        while(!pq.empty() || !waitQueue.empty()){
            time++;
            if(!pq.empty()){
                int freq=pq.top()-1;
                pq.pop();
                if(freq>0){
                    waitQueue.push({freq,time+n});
                }
            }
            if(!waitQueue.empty() && waitQueue.front().second==time){
                pq.push(waitQueue.front().first);
                waitQueue.pop();
            }
        }
        return time;
    }
};
