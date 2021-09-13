// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    
    void nextConn(Node* root)
    {
        if(!root)return ;
        if(root->next)
        {
            if(root->right)
            {
                if(root->next->left)
                root->right->next=root->next->left;
                else if(root->next->right)
                {
                root->right->next=root->next->right;    
                }
                nextConn(root->next);
            }
            else if(root->left)
            {
                if(root->next->left)
                root->left->next=root->next->left;
                else if(root->next->right)
                {
                root->left->next=root->next->right;    
                }
                nextConn(root->next);
            }
        }
        else
        return ;
    }
    
    void lr(Node* root)
    {
        if(!root)return ;
        if(root->left and root->right)
        root->left->next=root->right;
        if(root->left)
        nextConn(root->left);
        else
        nextConn(root->right);
        
        lr(root->left);
        lr(root->right);
    }

    Node* connect(Node* root) {
        root->next=NULL;
        lr(root);
        return root;
    }
};