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
    int partitionDisjoint(vector<int>& nums) {
        vector<int>miniRight(nums.size());
        vector<int>maxiLeft(nums.size());
        
        maxiLeft[0]=nums[0];
        miniRight[nums.size()-1]=nums[nums.size()-1];
        
        for(int i=nums.size()-2;i>=0;i--)
        miniRight[i]=min(miniRight[i+1],nums[i]);
        
        for(int i=1;i<nums.size();i++)
        maxiLeft[i]=max(maxiLeft[i-1],nums[i]);
        
        int i=0,j=1;
        
        while(i<nums.size() and j<nums.size() and maxiLeft[i]>miniRight[j])
        {
            i++;
            j++;
        }
        return i+1;
    }
};