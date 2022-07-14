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
    void traverse(Node* root)
    {      
        if(!root->left and !root->right)return ;
        Node* tp=root;
        while(tp)
        {            
            if(tp->left and tp->right)
            {
                tp->left->next=tp->right;            
            }
            Node* toConnect=tp->right!=NULL ? tp->right : tp->left; 
            Node* tfp= tp->next;
            if(tfp)
            {                
                toConnect->next = tfp->left != NULL ? tfp->left : tfp->right;
            }
            tp=tfp;
        }
        if(root->left)traverse(root->left);
        if(root->right)traverse(root->right);
    }
    Node* connect(Node* root) {    
        if(!root)return root;
        traverse(root);
        return root;
    }
};