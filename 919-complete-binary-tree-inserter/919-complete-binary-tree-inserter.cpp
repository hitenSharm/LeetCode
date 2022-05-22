/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
	TreeNode* r;	
    CBTInserter(TreeNode* root) {        
		r=root;
		return ;
    }
    
    int insert(int val) {        
		queue<TreeNode*>q;
		q.push(r);
		while(!q.empty())
		{
			int len=q.size();
			for(int i=0;i<len;i++)
			{
				TreeNode* t=q.front();
                q.pop();
				if(!t->left)
				{
					t->left=new TreeNode(val);
					return t->val;
				}
				if(!t->right)
				{
					t->right=new TreeNode(val);
					return t->val;
				}
				q.push(t->left);
				q.push(t->right);                
			}
		}
		return 0;
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */