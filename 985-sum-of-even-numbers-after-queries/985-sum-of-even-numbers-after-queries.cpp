class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int>ump;
        int s=0;
        for(auto i:nums)
        {
            if(i%2==0)s+=i;
            ump[i]++;
        }
        vector<int>ans;
        for(auto q:queries)
        {
            int index=q[1];
            int value=q[0];
            ump[nums[index]]--;
            if(nums[index]%2==0)s-=nums[index];
            nums[index]+=value;
            if(nums[index]%2==0)s+=nums[index];
            ump[nums[index]]++;
            ans.push_back(s);
        }
        return ans;
    }
};