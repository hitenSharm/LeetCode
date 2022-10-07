class MyCalendarThree {
public:
    vector<int>arr;
    vector<int>dep;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        arr.push_back(start);
        dep.push_back(end);
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        int ans=0;
        while(i<arr.size() and j<arr.size())
        {
            while(i<arr.size() and arr[i]<dep[j])
            {
                i++;
            }
            ans=max(ans,i-j);
            j++;
        }
        return ans;
    }
};        
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */