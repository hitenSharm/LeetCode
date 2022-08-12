class MyQueue {
public:
    stack<int>ip;
    stack<int>op;
    MyQueue() {        
    }
    
    void push(int x) {
        ip.push(x);
    }
    
    int pop() {
        if(op.size()==0)
        {
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }            
        }
        int x=op.top();
        op.pop();
        return x;
    }
    
    int peek() {
        if(op.size()==0)
        {
            while(!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }            
        }
        return op.top();
    }
    
    bool empty() {
        if(!ip.empty() || !op.empty())return false;
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