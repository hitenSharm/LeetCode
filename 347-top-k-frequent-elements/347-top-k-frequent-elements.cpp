class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //nlogk Solution
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++)ump[nums[i]]++;
        priority_queue<pi,vector<pi>,greater<pi>>minHeap;
        for(auto it:ump)
        {
            if(minHeap.size()<k)
            minHeap.push({it.second,it.first});
            else
            {
                //cout<<minHeap.top().first<<" "<<it.second<<endl;
                if(minHeap.top().first<it.second)
                {
                    minHeap.pop();
                    minHeap.push({it.second,it.first});
                }
            }
        }
        vector<int>ans;
        while(!minHeap.empty())
        {
            //cout<<minHeap.top().second<<" "<<minHeap.top().first<<endl;
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};