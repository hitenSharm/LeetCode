class Solution {
public:
    
    int findPivot(vector<int>& nums)
    {
        if(nums.size()==1)return 0;
        //if(nums[0]>nums[1])return 0;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m = l + (r-l)/2;            
            if(nums[m]>nums[m+1])return m;
            else if(nums[m]>nums[nums.size()-1])
            {
                l=m+1;
            }
            else
                r=m-1;
        }
        return -1;
    }
    
    int bs(vector<int>& nums,int& t,int l,int r)
    {        
        while(l<=r)
        {
            int m = l+ (r-l)/2;
            if(nums[m]==t)return m;
            if(nums[m]<t)l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)return nums[0]==target ? 0 : -1;        
        int idx=findPivot(nums);
        cout<<idx<<endl;
        int ans=bs(nums,target,0,idx);
        ans=max(ans,bs(nums,target,idx+1,nums.size()-1));
        return ans;
    }
};