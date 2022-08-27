class MaxStack {
    private:
    list<int>dll;
    map<int,vector<list<int>::iterator>>bst;    
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        dll.push_back(x);
        auto it=dll.end();
        it--;
        bst[x].push_back(it);
    }
    
    int pop() {
        int ele=dll.back();
        auto it=dll.end();
        it--;
        bst[ele].pop_back();
        if(bst[ele].size()==0)bst.erase(ele);
        dll.pop_back();
        return ele;
    }
    
    int top() {
      return dll.back();
    }
    
    int peekMax() {
       return bst.rbegin()->first;
    }
    
    int popMax() {
        int ele = bst.rbegin()->first;
        auto it=bst[ele].back();
        dll.erase(it);
        bst[ele].pop_back();
        if(bst[ele].size()==0)bst.erase(ele);
        return ele;
    }
};