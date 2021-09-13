// https://leetcode.com/problems/gray-code

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

    bool recu(vector<int>& ans,unordered_set<int>& vis,int& n)
    {
        if(ans.size() == (1<<n))return true;
        
        int curr=ans[ans.size()-1];
        for(int i=0;i<n;i++)
        {
            int candid=curr ^ (1<<i);
            if(vis.find(candid) == vis.end())
            {
                vis.insert(candid);
                ans.push_back(candid);
                if(recu(ans,vis,n))return true;
                vis.erase(candid);
                ans.pop_back();
            }
        }
        
        return false;
    }

    vector<int> grayCode(int n) {
        vector<int>ans;
        ans.push_back(0);
        unordered_set<int>vis;
        vis.insert(0);
        recu(ans,vis,n);
        return ans;
    }
};