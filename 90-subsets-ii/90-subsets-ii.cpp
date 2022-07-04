class Solution {
public:

	vector<vector<int>>ans;

	void recu(vector<int>& nums,vector<int>& temp,int index)
	{
		if(index>=nums.size())return ;
        
		for(int i=index;i<nums.size();i++)
		{
			if(i==index || nums[i]!=nums[i-1])//this is to remove duplicates as it will get 1 2 2 2 --> 1 2(1st index)->recu & 1 2(not taken) 2(2nd index) wont happen as prev was taken
			{
				temp.push_back(nums[i]);
                ans.push_back(temp);
				recu(nums,temp,i+1);
				temp.pop_back();
			}
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        recu(nums,temp,0);
        ans.push_back({});
        return ans;
    }
};