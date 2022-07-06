class Solution {
public:
	stack<int>st;	
	unordered_set<int>traversedNodes;
	bool valid=true;

	void recu(int curr,unordered_map<int,vector<int>>& adjList,vector<int>vis)
	{		
		if(!valid)return ;
		vis[curr]=1;
		traversedNodes.insert(curr);
		vector<int>& candid=adjList[curr];
		for(int i=0;i<candid.size();i++)
		{			
			if(vis[candid[i]]!=0)
			{
				valid=false;
				return ;
                //this should be doing cycle detection by dfs
                //this is like keeping track of recursion stack
                //a better apporach is to pass by address the vis array
                //make vis[current]=1;
                //then traverse
                //make vis[current]=0; ---> make move,explore,unmake move
			}
			if(traversedNodes.find(candid[i])!=traversedNodes.end())continue ;
			recu(candid[i],adjList,vis);            
		}
		st.push(curr);
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adjList;    	

        for(int i=0;i<prerequisites.size();i++)
        	adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
                
        for(int i=0;i<numCourses;i++)
        {
        	if(traversedNodes.find(i)!=traversedNodes.end())continue ;
        	vector<int>vis(numCourses,0);
        	recu(i,adjList,vis);
        	if(!valid)return {};
        }        
        vector<int>ans;
        while(!st.empty())
        {
        	ans.push_back(st.top());
        	st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};