// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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

    TreeNode* traverse(int l,int r,vector<int>& nums)
    {
        if(l>r)return nullptr;
        int m=l+(r-l)/2;        
        TreeNode* root=new TreeNode(nums[m]);        
        root->left=traverse(l,m-1,nums);        
        root->right=traverse(m+1,r,nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=traverse(0,nums.size()-1,nums);
        return root;
    }
};