class Solution
{
    public:
        vector<int> inorderTraversal(TreeNode *root)
        {
            vector<int> ans;
            while (root)
            {
                if (!root->left)
                {
                    ans.push_back(root->val);
                    root = root->right;
                   	//as no leftmost so we dont need to make thread to connect 
                }
                else
                {
                    TreeNode *prev = root->left;
                    while (prev->right and prev->right != root)	//all connections happen from the left side, i go to the rightmost node in the left tree
                    {
                        prev = prev->right;
                    }
                   	//no thread
                    if (!prev->right)
                    {
                        prev->right = root;	//make thread
                       	//as the connection is made, go to the node
                        root = root->left;
                    }
                    else
                    {
                       	//this means there is a thread present
                        prev->right = nullptr;
                        ans.push_back(root->val);
                        root = root->right;	//as when i arrived here it meant i finished my traversal                    
                    }
                }
            }
            return ans;
        }
};