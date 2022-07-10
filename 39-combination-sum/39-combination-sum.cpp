class Solution {
public:

	vector<vector<int>>ans;

	void recu(vector<int>& candidates,int index,vector<int>& temp,int target)
	{
		if(target==0)
		{
			ans.push_back(temp);
			return ;
		}
		if(target<0 || index>=candidates.size())return ;
		for(int i=index;i<candidates.size();i++)
		{
			temp.push_back(candidates[i]);			
			recu(candidates,i,temp,target-candidates[i]);
			temp.pop_back();
		}
	}


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;        	
        recu(candidates,0,temp,target);
        return ans;
    }
};