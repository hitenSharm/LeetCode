// https://leetcode.com/problems/3sum

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        map<vector<int>,int>s;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r)
            {
                if(x+nums[l]+nums[r]==0 and s.find({x,nums[l],nums[r]})==s.end())
                {
                    ans.push_back({x,nums[l],nums[r]});
                    s[{x,nums[l],nums[r]}]=1;
                    l++;
                    r--;
                }
                else if(x+nums[l]+nums[r]<0)
                {
                    l++;
                }
                else
                r--;
            }
        }
        return ans;
    }
};