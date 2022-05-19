class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        //leaf nodes are useless for min height so we can remove them
		//in the end we will have 2 or less nodes which will give min height
		//the mid nodes from leaf to leaf are the answer
		//adj list has to be a vector of sets for removal of leaf nodes at each iteration
		vector<unordered_set<int>>adj(n);
		for(int i=0;i<edges.size();i++)
		{
			adj[edges[i][0]].insert(edges[i][1]);
			adj[edges[i][1]].insert(edges[i][0]);
		}
		//now i need to remove nodes with degree 1, they have to be removed
		//fast so we need a queue otherwise we will have to iterate through the list repeatedly
		queue<int>q;
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()==1)q.push(i);
		}
		//remove leaf nodes
		//n>2 as in the end we must have 2 or 1 nodes
		while(n>2)
		{
			int len=q.size();
			n-=len;
			//remove all edge nodes at once
			for(int j=0;j<len;j++)
			{
				int leaf=q.front();
				q.pop();
				for(auto it=adj[leaf].begin();it!=adj[leaf].end();it++)
				{
					int conn=*it;
					adj[conn].erase(leaf);
					if(adj[conn].size()==1)q.push(conn);
				}				
			}
		}
		vector<int>ans;
		while(!q.empty())
		{
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
    }
};