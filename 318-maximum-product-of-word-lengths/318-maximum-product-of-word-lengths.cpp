class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<char,set<int>>ump;
		for(int i=0;i<words.size();i++)
		{
			string &s=words[i];
			for(int j=0;j<s.size();j++)
			{
				ump[s[j]].insert(i);
			}
		}
		int ans=0;
		for(int i=0;i<words.size();i++)
		{
			string &s=words[i];
			vector<int>vis(words.size(),0);
			for(int j=0;j<s.size();j++)
			{
				set<int>& st=ump[s[j]];
				for(const int &it:st)
				{
					vis[it]=1;
				}
			}
			for(int j=vis.size()-1;j>=0;j--)
			{
				if(vis[j]==0)
				{
					int t1=words[j].size()*words[i].size();
					ans=max(ans,t1);
				}
			}
		}
		return ans;
    }
};