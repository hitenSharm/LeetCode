class Solution {
public:
	vector<int>dp;

	int findIndex(vector<vector<int>>& jobs,int& lastIndex)
	{		
		int ending=jobs[lastIndex][1];        
		int l=lastIndex,r=jobs.size()-1;
		int ans=jobs.size();
		while(l<=r)
		{
			int m=l+(r-l)/2;
			if(jobs[m][0]<ending)
				l=m+1;
			else
			{
				ans=m;
				r=m-1;
			}
		}
		return ans;
	}

	int recu(vector<vector<int>>& jobs,int index)
	{
		if(index>=jobs.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int nextIndex=findIndex(jobs,index);
        int ans=max(recu(jobs,index+1),jobs[index][2]+recu(jobs,nextIndex));
        return dp[index]=ans;
	}

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        dp.resize(startTime.size(),-1);
        for(int i=0;i<startTime.size();i++)
        {
        	jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());        
        
        return recu(jobs,0);        
    }
};