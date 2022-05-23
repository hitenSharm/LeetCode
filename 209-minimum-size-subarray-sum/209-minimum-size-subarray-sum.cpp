class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size()+1;
		int i=0,j=0;
		int s=0;
		while(i<nums.size())
		{
			while(j<nums.size() and s<target)
			{
				s+=nums[j];
				j++;
			}	
            if(s>=target)
			len=min(len,j-i);
            if(len==1)return len;
			s-=nums[i];
			i++;
		}
        if(len==nums.size()+1)len=0;
		return len;
    }
};