// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {        
        vector<int>prefix;
        int s=0;
        prefix.push_back(s);
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            prefix.push_back(s);
            ump[s]++;
        }
        int cnt=0;
        for(int i=0;i<prefix.size();i++)
        {            
            if(ump.find(prefix[i]+k)!=ump.end())
            {
                cnt+=ump[prefix[i]+k];
            }
        }
        return cnt;
    }
};