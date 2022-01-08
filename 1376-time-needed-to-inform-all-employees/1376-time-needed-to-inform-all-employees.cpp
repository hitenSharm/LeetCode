class Solution {
public:

    void dfs(unordered_map<int,vector<int>>& ump,vector<int>& informTime,int& maxi,int curr,int val)
    {
        if(ump[curr].size()==0)return ;
        vector<int>& tmp=ump[curr];
        for(int i=0;i<tmp.size();i++)
        {
            maxi=max(maxi,val+informTime[curr]);
            dfs(ump,informTime,maxi,tmp[i],val+informTime[curr]);
        }
        return ;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>ump;
        int st,maxi=0;
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]==-1)st=i;
            else
            ump[manager[i]].push_back(i);
        }
        dfs(ump,informTime,maxi,st,0);
        return maxi;
    }
};