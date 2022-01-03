class BrowserHistory {
public:
    stack<string>st1,st2;
    BrowserHistory(string homepage) {
        st1.push(homepage);
    }
    
    void visit(string url) {
        st1.push(url);
        while(!st2.empty())st2.pop();
    }
    
    string back(int steps) {
        while(steps>0 and !st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
            steps--;
        }
        if(st1.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return st1.top();
    }
    
    string forward(int steps) {
        while(steps>0 and !st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
            steps--;
        }
        return st1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */