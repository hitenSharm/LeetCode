class Solution {
public:
    string simplifyPath(string path) {
        deque<string>dq;
        path+="/";		
		
		for(int i=1;i<path.size();)
		{
			string s="";
			while(path[i]!='/')
			{
				s+=path[i];
				i++;
			}
			while(i<path.size() and path[i]=='/')i++;
			if(s==".." and dq.size()>0)dq.pop_back();
			else if(s!="." and s.size()>0 and s!="..")dq.push_back(s);			
		}

		string ans="/";
		while(!dq.empty())
		{
			ans+=dq.front()+"/";
			dq.pop_front();
		}
		if(ans.size()>1)ans.pop_back();
		return ans;
    }
};