// https://leetcode.com/problems/range-sum-query-mutable

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class NumArray {
public:

    vector<int>bit;
    int n;
    vector<int>globe;
    
    NumArray(vector<int>& nums) {
        n=nums.size()+1;
        globe=nums;
        bit.resize(n,0);
        for(int i=0;i<nums.size();i++)
        {
            init(i,nums[i]);            
        }
    }
    
    void init(int index,int val)
    {
        index++;
        for(; index<n ; index+=(index & -index))
        {
            bit[index]+=val;
        }
    }
    
    void update(int index, int val) {
        int diff=val-globe[index];
        globe[index]=val;
        init(index,diff);
    }
    
    int sumRange(int left, int right) {
        int ansL=0,ansR=0;
        left;right++;
        for(;left>0 ; left-=(left & -left))
        {
            ansL+=bit[left];
        }
        for(;right>0 ; right-=(right & -right))
        {
            ansR+=bit[right];
        }
        return (ansR-ansL);
    }
};
