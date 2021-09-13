// https://leetcode.com/problems/long-pressed-name

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        while(i<name.length() || j<typed.length())
        {
        	char curr=name[i];
        	if(name[i]!=typed[j])
        		return false;
        	i++;
        	j++;
        	if(name[i]!=typed[j])
        	{
        		while(curr==typed[j])
        			j++;
        	}
        }
        return true;
    }
};