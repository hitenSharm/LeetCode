#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q;
    void push(int x) {
        queue<int>tmp;
		while(!q.empty())
		{
			tmp.push(q.front());
			q.pop();
		}
		q.push(x);
		while(!tmp.empty())
		{
			q.push(tmp.front());
			tmp.pop();
		}
    }
    
    int pop() {
        int x=q.front();
		q.pop();
		return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return (q.size()==0);
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