class RecentCounter {
public:
   queue<int>q1;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q1.push(t);
        while(!q1.empty() && q1.front()<t-3000){
            q1.pop();
        }
        return q1.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */