// https://leetcode.com/problems/top-k-frequent-elements

#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        for(int i:nums)
        {
            ump[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:ump)
        {
            pq.push(make_pair(it.second,it.first));
        }
        vector<int>sol;
        for(int i=0;i<k;i++)
        {
            int temp=pq.top().second;
            sol.push_back(temp);
            pq.pop();
        }
        return sol;
    }
};