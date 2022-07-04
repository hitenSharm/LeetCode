class Solution {
public:
	vector<vector<string>>ans;

	void recu(string& s,int index,vector<string>& temp)
	{
		if(index>=s.size())//base case
		{
			ans.push_back(temp);
			return ;
		}
		//gen all substrings
		for(int i=index;i<s.size();i++)
		{
			string substring=s.substr(index,i - index + 1); //as it is pos,pos+len
			string substring2=substring;
			reverse(substring.begin(),substring.end());
			if(substring==substring2)
			{
				temp.push_back(substring);
				recu(s,i+1,temp);//means generated a correct substring till this point
				temp.pop_back();
			}
		}

	}

    vector<vector<string>> partition(string s) {
        vector<string>temp;        
        recu(s,0,temp);
        return ans;
    }
};