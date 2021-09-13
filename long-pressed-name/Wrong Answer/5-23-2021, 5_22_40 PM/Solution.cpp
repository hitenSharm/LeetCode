// https://leetcode.com/problems/long-pressed-name

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;        
        for(int t=0;t<typed.length();t++)
        {
        	if(typed[t]==name[i])
        		i++;
        }
        if(i==name.length())
        	return true;
        return false;
    }
};