class MyQueue {
    private:
    stack<int>st1;
    stack<int>st2;
    stack<int>temp;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st2.push(x);
    }
    
    int pop() {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }

        if(st1.empty() == true) return -1;

        int el = st1.top();
        st1.pop();

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        return el;
    }
    
    int peek() {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }

        if(st1.empty() == true) return -1;
        int el = st1.top();
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return el;
    }
    
    bool empty() {
        if(st1.empty() ==  false || st2.empty() == false) return false;
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */