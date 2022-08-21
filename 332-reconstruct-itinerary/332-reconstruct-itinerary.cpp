class Solution {
public:
	unordered_map<string,multiset<string>>adj;
	vector<string>ans;
    
    void recu(string curr){
        
        while(adj[curr].size()>0)//imp method to get next here as at times it becomes 0
        {
            string next=*adj[curr].begin();
            adj[curr].erase(adj[curr].begin());
            recu(next);
        }
        
        ans.push_back(curr);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);//make graph and lexo sorted
        }
        
        recu("JFK");
	    
        reverse(ans.begin(),ans.end());
        return ans;
    }
};