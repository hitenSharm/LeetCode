class Solution {
public:

	int sum2(int t,vector<int>& n,int idx)
	{
		int l=idx;
		int r=n.size()-1;
		int ans;
		int diff=INT_MAX;
		while(l<r and l>=idx)
		{
			int tSum=n[l]+n[r];
			if(diff>abs(tSum-t))
			{
				diff=abs(tSum-t);
				ans=tSum;
			}
			if(tSum>t){
				r--;
			}
			else
			l++;
		}
		return ans;
	}

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
		int ans;
		int diff=INT_MAX;
		for(int i=0;i<=nums.size()-3;i++)
		{			
			int temp=sum2(target-nums[i],nums,i+1);
			temp+=nums[i];
			if(diff>abs(temp-target))
			{
				diff=abs(temp-target);
				ans=temp;
			}
		}
		return ans;
    }
};

//-4 -1 1 2