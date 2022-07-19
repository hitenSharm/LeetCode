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

    int value(int n)
    {
      int ans=0;
      while(n>0)
      {
        ans+=n%10;
        n=n/10;
      }
      return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>ump;
        for(int i=0;i<nums.size();i++)
        {
          int brokenDownValue=value(nums[i]);
          ump[brokenDownValue].push_back(nums[i]);
        }
        int ans=-1;
        for(auto it:ump)
        {
          vector<int>& temp=it.second;
            if(temp.size()<2)continue ;
          sort(temp.begin(),temp.end());
          int lastIndex=temp.size()-1;
          ans=max(ans,temp[lastIndex]+temp[lastIndex-1]);
        }
        return ans;
    }
};