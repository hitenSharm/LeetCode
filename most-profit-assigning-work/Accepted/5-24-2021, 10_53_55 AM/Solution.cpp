// https://leetcode.com/problems/most-profit-assigning-work

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        int i=0;int ans=0;int j=0;      
        vector<pair<int,int>>vec;
        for(int i=0;i<difficulty.size();i++)
        {
        	vec.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(vec.begin(),vec.end());
        int mxProfit=0;
        while(i<worker.size() && j<vec.size())
        {            
        	while(j<vec.size() && vec[j].first<=worker[i])
        	{                
        		mxProfit=max(mxProfit,vec[j].second);
        		if(j+1<vec.size())
                    j++;
                else
                    break;
        	}            
            cout<<mxProfit<<endl;
        	ans+=mxProfit;
        	i++;
        }
        return ans;

    }
};