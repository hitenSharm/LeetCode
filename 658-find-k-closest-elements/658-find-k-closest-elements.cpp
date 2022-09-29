class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi>pq;
        for(int i=0;i<arr.size();i++)
        {
            int y=abs(x-arr[i]);
            pq.push({y,arr[i]});
            if(pq.size()>k)pq.pop();
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        //nlogk + klogk
        return ans;
    }
};