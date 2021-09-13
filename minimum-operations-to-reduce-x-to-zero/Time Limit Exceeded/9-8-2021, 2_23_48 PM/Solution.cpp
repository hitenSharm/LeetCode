// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        queue<pair<int,pair<int,int>>>q;
        q.push({x,{0,nums.size()-1}});
        int lvl=0;
        while(!q.empty())
        {
            int len=q.size();
            lvl++;
            for(int k=0;k<len;k++)
            {
                pair<int,pair<int,int>>& p=q.front();
                pair<int,int>& p2=p.second;
                int i=p2.first,j=p2.second;                    
                if(p.first-nums[i]==0 || p.first-nums[j]==0)return lvl;
                if(p.first-nums[i]>0)
                {
                    if(i+1<nums.size())
                    q.push({p.first-nums[i],{i+1,j}});
                }
                if(j-1>i and p.first-nums[j]>0)
                {
                    if(j-1>=0)
                    q.push({p.first-nums[j],{i,j-1}});
                }
                q.pop();
            }
        }
        return -1;
    }
};