class Solution {
public:
	vector<vector<int>>ans;

	void recu(vector<int>& candidates, int target,vector<int>& temp,int index,int currSum)
	{		
		if(currSum==target)
		{
			ans.push_back(temp);return ;
		}
		if(index>=candidates.size())return ;
		for(int i=index;i<candidates.size();i++)
		{
			if(currSum+candidates[i]>target)continue ;
			if(i==index || candidates[i]!=candidates[i-1])
			{
				temp.push_back(candidates[i]);
				recu(candidates,target,temp,i+1,currSum+candidates[i]);
				temp.pop_back();
			}
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>());
        vector<int>temp;
        recu(candidates,target,temp,0,0);
        return ans;
    }
};