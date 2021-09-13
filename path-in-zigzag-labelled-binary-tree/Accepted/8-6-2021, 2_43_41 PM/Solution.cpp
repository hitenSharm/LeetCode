// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree

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
    vector<int> pathInZigZagTree(int label) {
        int lvl=log2(label)+1;
        vector<int>ans;
        int index=-1;
        ans.push_back(label);
        while(lvl>=1)
        {            
            if(lvl%2==0)
            {
                int l=pow(2,lvl-1);
                int r=pow(2,lvl)-1;
                if(index==-1)
                {
                    index=r-label+l;
                }
                else
                {
                    int val=r-index+l;
                    ans.push_back(val);
                }
            }
            else
            {
                if(index==-1)index=label;
                else
                ans.push_back(index);
            }
            index=index/2;
            lvl--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};