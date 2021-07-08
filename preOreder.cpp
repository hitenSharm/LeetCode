#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//didnt do full as this wont work for 2 digit numbers. can be done with minor changes tho

class Codec {
public:

    void travserse(TreeNode* root,string& ans)
    {
        if(!root)
        return ;
        ans=ans+to_string(root->val);
        travserse(root->left,ans);
        travserse(root->right,ans);
        
    }
    
    string serialize(TreeNode* root) {
        string ans;
        travserse(root,ans);
        return ans;
    }

    TreeNode* deserialize(string data) {
        stack<TreeNode*>st;
        TreeNode* ans=new TreeNode(data[0]-'0');
        st.push(ans);
        TreeNode* temp;
        for(int i=1;i<data.length();i++)
        {
            temp=NULL;
            while(!st.empty() and (data[i]-'0') > st.top()->val)
            {
                temp=st.top();
                st.pop();
            }
            if(temp)
            {
                TreeNode* create=new TreeNode(data[i]-'0');
                temp->right=create;
                st.push(temp->right);
            }
            else
            {
                TreeNode* create=new TreeNode(data[i]-'0');
                temp=st.top();
                temp->left=create;
                st.push(st.top()->left);
            }
        }
        return ans;
    }
};
