class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>vis;
        for(auto it:nums)
            vis.insert(it);
        int ans=0;
        for(auto it:nums)
        {
            if(vis.find(it)==vis.end())continue ;
            queue<int>q;
            q.push(it);
            int temp=1;
            vis.erase(it);
            while(!q.empty())
            {
                int ele=q.front();
                q.pop();                
                if(vis.find(ele+1)!=vis.end()){
                    q.push(ele+1);
                    vis.erase(ele+1);
                    temp++;
                }
                if(vis.find(ele-1)!=vis.end()){
                    q.push(ele-1);
                    vis.erase(ele-1);
                    temp++;
                }
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};