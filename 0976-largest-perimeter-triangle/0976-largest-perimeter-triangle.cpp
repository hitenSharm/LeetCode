class Solution {
public:
    
    int valid(int a,int b,int c)
    {        
        if(a+b>c and a+c>b and b+c>a){
            return a+b+c;
        }
        return 0;
    }
    
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            ans=max(ans,valid(nums[i],nums[i+1],nums[i+2]));
        }
        return ans;
    }
};