class Solution {
public:
	const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string>ans;
    string temp="";
    void recu(string& digits,int index)
    {
    	if(index>=digits.size())
    	{
    		ans.push_back(temp);
    		return ;
    	}
    	string candidates=pad[digits[index]-'0'];
    	for(int i=0;i<candidates.size();i++)
    	{
    		temp+=candidates[i];
    		recu(digits,index+1);
    		temp.pop_back();
    	}
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
    	recu(digits,0);
    	return ans;
    }
};