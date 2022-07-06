class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int l=0,r=nums.size()-1;
        if(nums[0]!=nums[1])return nums[0];
        if(nums[r]!=nums[r-1])return nums[r];
        while(l<=r)
        {
        	int mid=l+(r-l)/2;
        	//pair index property(all pairs start a even index and end at odd till the point we find a single sorted element)
        	if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])return nums[mid];
        	if((mid%2==0 and nums[mid]==nums[mid+1]) || (mid%2!=0 and nums[mid]==nums[mid-1]))l=mid+1;
        	else
        		r=mid-1;
        }
        return -1;
    }
};