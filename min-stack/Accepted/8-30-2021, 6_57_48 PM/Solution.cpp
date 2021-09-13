// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    stack<int>st;
    map<int, int>mp;
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    void pop() {
        int tmp=st.top();
        mp[tmp]--;
        if(mp[tmp]==0)mp.erase(tmp);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it=mp.begin();
        return it->first;
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