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
        if((!root->left and !root->right))return ; //return if leaf node
        Node* curr=root;
        Node* connectNext;
        while(curr)
        {
            Node* c1=curr->left;
            Node* c2=curr->right;            
            if(c1 and c2){
                c1->next=c2;
                connectNext=c2;
            }else if(c1)
            {
                connectNext=c1;
            }
            else if(c2){
                connectNext=c2;
            }
            
            if(curr->next)
            {
                connectNext->next=(curr->next->left!=nullptr ? curr->next->left : curr->next->right);
            }
            curr=curr->next;
        }        
        traverse(root->left);
        traverse(root->right);
    }
    
    Node* connect(Node* root) {
        if(!root)return root;
        root->next=nullptr;
        traverse(root);
        return root;
    }
};