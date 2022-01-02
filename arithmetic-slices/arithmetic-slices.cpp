class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)return 0;
        int i=0,j=1;
        int diff=nums[j]-nums[i];
        int ans=0;
        int len=0;
        j=2;
        while(j<nums.size())
        {
            if(nums[j]-nums[j-1]==diff)j++;
            else
            {
                j--;
                len=j-i+1;
                if(len>=3)
                ans+=(len*(len+1)/2)-len-(len-1);
                i=j;
                j++;
                diff=nums[j]-nums[i];
                len=0;
            }
        }
        j--;
        len=j-i+1;        
        if(len>=3)ans+=(len*(len+1)/2)-len-(len-1);
        
        return ans;
    }
};