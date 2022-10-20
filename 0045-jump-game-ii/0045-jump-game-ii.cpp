class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int prevFinal=nums[0];
        int currFinal=nums[0];
        int ans=0;
        for(int i=1;i<=currFinal;i++)
        {
            if(i>=nums.size()-1)break;            
            currFinal=max(currFinal,i+nums[i]);
            if(i==prevFinal){
                ans++;
                prevFinal=currFinal;
            }
        }
        if(prevFinal>=nums.size()-1)ans++;
        return ans;
    }
};