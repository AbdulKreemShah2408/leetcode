class MinStack {
public:
 stack<long long int>s;
 long long int minValue;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minValue=value;
        }
        else{
            if(value<minValue){
                s.push((long long)2*value-minValue);
                minValue=value;
            }
            else{
                s.push(value);
            }
        }
    }
    
    void pop() {
     if(s.top()<minValue){
        minValue=2*minValue-s.top();
     }
     s.pop();
        
    }
    
    int top() {
     if(s.top()<minValue){
        return minValue;
     }
     return s.top();
    }
    
    int getMin() {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */