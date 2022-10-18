class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ust(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums)
        {
            if(ust.find(it)==ust.end())continue ;
            int temp=0;
            queue<int>q;//at most 2 ele at a time
            q.push(it);
            ust.erase(it);
            while(!q.empty())
            {
                int ele=q.front();
                temp++;
                q.pop();
                if(ust.find(ele+1)!=ust.end())
                {
                    ust.erase(ele+1);//remove repetetions
                    q.push(ele+1);
                }
                if(ust.find(ele-1)!=ust.end())
                {
                    ust.erase(ele-1);
                    q.push(ele-1);
                }
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};