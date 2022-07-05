class Solution {
public:
	vector<vector<int>>ans;

	void recu(vector<int>& nums,int index)
	{
		if(index>=nums.size())
		{
			ans.push_back(nums);//i generated all swaps for this recursion
			return ;
		}
		for(int i=index;i<nums.size();i++)
		{
			//either i can swap this index with some other index in front and generate a permutation
			//or i can skip this index and start from the next index
			swap(nums[index],nums[i]);
			recu(nums,index+1);//index + 1 and not i+1 as i am swapping from the 'index'
			swap(nums[index],nums[i]);
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
        //O(1) space
    	recu(nums,0);
    	return ans;
    }
};