class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int req;
    KthLargest(int k, vector<int>& nums) {
        req=k;
        if(nums.size()==0)return ;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size()<k)pq.push(nums[i]);
            else if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()==0 || pq.size()<req){
            pq.push(val);
            return pq.top();
        }
        if(val<pq.top())return pq.top();
        pq.pop();
        pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */