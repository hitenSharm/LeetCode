// https://leetcode.com/problems/long-pressed-name

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;        
        int j;
        for(j=0;j<typed.length();j++)
        {
        	if(typed[j]==name[i])
        		i++;
        	if(i==name.length())
        		break;
        }
        if(i==name.length() && j==typed.length()-1)
        	return true;
        return false;
    }
};