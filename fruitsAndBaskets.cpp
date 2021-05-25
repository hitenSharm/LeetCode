#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();


class Solution {
public:
    
    int totalFruit(vector<int>& tree) {
		int len=0;
		int i=0;int j=0;
		unordered_map<int,int>ump;
		int n=tree.size();
		while(i<n && j<n)
		{
			while(j<n && ump.size()<=2)
			{
                if(ump.find(tree[j])==ump.end() && ump.size()==2)
                    break;
				ump[tree[j]]++;
				j++;
			}
			len=max(len,j-i);            
			ump[tree[i]]--;
			if(ump[tree[i]]==0)
				ump.erase(tree[i]);
			i++;
		}       
		return len;         
    }
};