/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        while(!q.empty())
        {
        	int len=q.size();
        	while(len--)
        	{
        		TreeNode* temp=q.front();
        		q.pop();
        		if(!temp)
        		{
        			ans+="#,";
        			continue ;
        		}
        		ans+=to_string(temp->val)+",";
        		q.push(temp->left);
        		q.push(temp->right);
        	}
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {   
        if(data.size()==0)return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
        	TreeNode* node=q.front();
        	q.pop();
        	getline(s,str,',');
        	if(str == "#")node->left=nullptr;
        	else
        	{
        		node->left=new TreeNode(stoi(str));
        		q.push(node->left);
        	}
        	getline(s,str,',');
        	if(str == "#")node->right=nullptr;
        	else
        	{
        		node->right=new TreeNode(stoi(str));
        		q.push(node->right);
        	}

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));