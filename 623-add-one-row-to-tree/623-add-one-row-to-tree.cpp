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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* r=new TreeNode(val);
            r->left=root;
            return r;
        }
        queue<TreeNode*>q;
        int lvl = 1;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if (lvl == depth - 1) {
                    TreeNode* rl = curr->left;
                    TreeNode* rr = curr->right;
                    curr->left = new TreeNode(val);
                    curr->right = new TreeNode(val);
                    curr->left->left = rl;
                    curr->right->right = rr;
                }
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            lvl++;
            if (lvl == depth)break;
        }
        return root;
    }
};