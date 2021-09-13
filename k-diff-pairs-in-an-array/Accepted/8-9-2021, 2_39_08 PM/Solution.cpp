// https://leetcode.com/problems/k-diff-pairs-in-an-array

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
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        set<pair<int,int>>s;
        for(int i=0;i<nums.size();i++)
        ump[nums[i]]++;
        
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            ump[x]--;
            if(ump.find(x+k)!=ump.end() and ump[x+k]>0 and s.find({x+k,x})==s.end())
            {
                s.insert({x,x+k});
            }
            if(ump.find(x-k)!=ump.end() and ump[x-k]>0 and s.find({x-k,x})==s.end())
            {
                s.insert({x,x-k});
            }
            ump[x]++;
        } 
        // for(auto it:s)
        //     cout<<it.first<<" "<<it.second<<endl;
        return s.size();
    }
};