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

	vector<TreeNode*>genSubTrees(int lb,int ub)
	{
		if(lb>ub)return {nullptr};
		if(ub==lb)
        {
            TreeNode* l=new TreeNode(lb);
            return {l};
        }
		vector<TreeNode*>subTree;
		for(int i=lb;i<=ub;i++)
		{
			vector<TreeNode*> leftSubtrees=genSubTrees(lb,i-1);
			vector<TreeNode*> rightSubTrees=genSubTrees(i+1,ub);
			for(int j=0;j<leftSubtrees.size();j++)
			{
				for(int k=0;k<rightSubTrees.size();k++)
				{
					//gen sub tree and pushback to array
					TreeNode* root = new TreeNode(i);
					root->left=leftSubtrees[j];
					root->right=rightSubTrees[k];
					subTree.push_back(root);
				}
			}
		}
		return subTree;
	}

    vector<TreeNode*> generateTrees(int n) {
        return genSubTrees(1,n);
    }
};