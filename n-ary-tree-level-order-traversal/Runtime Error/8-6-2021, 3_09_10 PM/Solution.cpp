// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty())
        {
            int len=q.size();
            vector<int>temp;
            for(int i=0;i<len;i++)
            {
                Node* tmp=q.front();q.pop();
                temp.push_back(tmp->val);
                vector<Node*>& kids=tmp->children;
                for(int j=0;j<kids.size();j++)
                {
                    q.push(kids[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};