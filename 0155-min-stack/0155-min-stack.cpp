class MinStack {
private:
stack<pair<int,int>>st;
int mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first;
        }
        return -1;
        
    }
    
    int getMin() {
        return st.top().second;
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