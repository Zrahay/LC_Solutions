class MyStack {
    private:
    queue<int>q1;
    queue<int>q2;
    queue<int>temp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() {
        if(q1.empty() == true) return -1;

        int el = q1.front();
        q1.pop();
        return el;

    }
    
    int top() {
        if(q1.empty() == true) return -1;

        return q1.front();
    }
    
    bool empty() {
        if(q1.empty() == false) return false;

        return true;
    }
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */