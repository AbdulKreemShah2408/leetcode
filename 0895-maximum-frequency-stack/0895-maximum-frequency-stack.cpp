class FreqStack {
public:
    unordered_map<int,int>freqMap;
    unordered_map<int,stack<int>>groupMap;
    int maxFreq;

    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        freqMap[val]++;
        int currFreq=freqMap[val];
        if(currFreq>maxFreq){
            maxFreq=currFreq;
        }
        groupMap[currFreq].push(val);
    }
    
    int pop() {
        int val=groupMap[maxFreq].top();
        groupMap[maxFreq].pop();
        freqMap[val]--;
        if(groupMap[maxFreq].empty()){
            maxFreq--;
        }
       return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */