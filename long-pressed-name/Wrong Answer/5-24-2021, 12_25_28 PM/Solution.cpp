// https://leetcode.com/problems/long-pressed-name

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int freq[26]={0};
        int tempFreq[26]={0};
        int i=1;int j=0; char tc=name[0];
        freq[name[0]-'a']++;
        char cc=name[i];
        while(i<name.length())
        {  
        	if(i<name.length())
        	cc=name[i];

        	while(cc==tc && i<name.length())
        	{       
        		cc=name[i]; 		
        		freq[cc-'a']++;
        		i++;        		
        	}
        	while(j<typed.length())
        	{
        		if(typed[j]==tc)
        		{
        			tempFreq[tc-'a']++;
        			j++;        			
        		}
        		else
        		break;
        	}
        	if(freq[tc-'a']<=tempFreq[tc-'a'])
        	{
        		freq[tc-'a']=0;
        		tempFreq[tc-'a']=0;
        		tc=cc;
        	}
        	else
        		return false;
        }
        if(j<typed.length())
        {
        	while(j<typed.length())
        	{
        		if(tc!=typed[j])
        		return false;
        		j++;
        	}
        }
        return true;
    }
};