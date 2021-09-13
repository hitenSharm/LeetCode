// https://leetcode.com/problems/partition-labels

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int alpha[26][2];
        for(int i=0;i<26;i++)
        	alpha[i][0]=INT_MAX;
        
        for(int i=0;i<26;i++)
        	alpha[i][1]=0;
        

        for(int i=0;i<s.length();i++)
        {
        	alpha[s[i]-'a'][0]=min(alpha[s[i]-'a'][0],i);
        	alpha[s[i]-'a'][1]=max(alpha[s[i]-'a'][1],i);
        }

        vector<int>arr;
        int curr_max=alpha[s[0]-'a'][1];
        int curr_min=alpha[s[0]-'a'][0];
        int fl=0;
        int i;
        for(i=0;i<s.length();i++)
        {
        	if(i==curr_max)
        	{
        		arr.push_back(curr_max-curr_min+1);
        		if(i+1<s.length())
        		{
        			fl=0;
        			curr_max=alpha[s[i+1]-'a'][1];
        			curr_min=alpha[s[i+1]-'a'][0];
        			continue;
        		}
        		else
        		{
        			fl=1;
        			break;
        		}
        	}

        	if(alpha[s[i]-'a'][1]>curr_max)
        		curr_max=alpha[s[i]-'a'][1];
        }
        if(fl==0)
        	arr.push_back(curr_max-alpha[s[i]-'a'][0]+1);
        return arr;
    }
};