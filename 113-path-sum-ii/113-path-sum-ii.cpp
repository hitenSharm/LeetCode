#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
//all root to leaf paths that sum to n
class Solution {
public:

    vector<vector<int>>ans;
    bool isLeaf(TreeNode* r)
    {
        if (!r->left and !r->right)return true;
        return false;
    }

    void dfs(TreeNode* root, int& t,int s,vector<int>& temp)
    {
        if (!root)return;
        if (isLeaf(root))
        {
            if (s + root->val == t)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }

        temp.push_back(root->val);
        dfs(root->left, t, s + root->val, temp);
        dfs(root->right, t, s + root->val, temp);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)return ans;
        vector<int> temp;
        dfs(root, targetSum,0,temp);
        return ans;
    }
};