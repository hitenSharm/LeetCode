class Solution {
public:

	void recu(string s,vector<string>& ans,int open,int close,int n)
	{
		if(open+close==2*n)
		{
			ans.push_back(s);
			return ;
		}
		if(open<n)
		{
			s+='(';
			recu(s,ans,open+1,close,n);	
			s.pop_back();		
		}
		if(close<open)
		{
			s+=')';
			recu(s,ans,open,close+1,n);
			s.pop_back();
		}
	}

    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        vector<string>ans;
        string s="";
		recu(s,ans,open,close,n);
		return ans;
    }
};