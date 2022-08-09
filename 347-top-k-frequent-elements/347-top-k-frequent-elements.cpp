class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //frequncy sort kinda calc freq of each ele and based and then use another map to grp same freq ele together
        //max freq possible is arr size so jusr traverse the highest freq possible to get k elements
        unordered_map<int, int>freqCnt;
        
        for (auto i : nums)freqCnt[i]++;

        unordered_map<int, vector<int>>freq;

        for (auto it : freqCnt) {
            freq[it.second].push_back(it.first);
        }
        int r = nums.size();
        vector<int>ans;
        while (ans.size() < k)
        {
            if (freq.find(r) != freq.end())
            {
                vector<int>& ele = freq[r];
                for (auto it : ele) {
                    ans.push_back(it);
                    if (ans.size() == k)break;
                }
            }
            r--;
        }
        return ans;
    }
};