class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>ump1;
        unordered_map<string,int>ump2;
        s1+=" ";
        for(int i=0;i<s1.size()-1;)
        {
        	string temp="";            
        	while(s1[i]!=' ')
        	{
        		temp+=s1[i];
        		i++;
        	}
        	ump1[temp]++;	
        	i++;
        }
        s2+=" ";
        vector<string>ans;
        for(int i=0;i<s2.size()-1;)
        {
        	string temp="";
        	while(s2[i]!=' ')
        	{
        		temp+=s2[i];
        		i++;
        	}
        	ump2[temp]++;	        	
        	i++;
        }      
        for(auto it:ump1)
        {
        	if(it.second == 1 and ump2.find(it.first)==ump2.end())
        	{
        		ans.push_back(it.first);
        	}
        }
        for(auto it:ump2)
        {
        	if(it.second == 1 and ump1.find(it.first)==ump1.end())
        	{
        		ans.push_back(it.first);
        	}
        }
        return ans;
    }
};