/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    stack<Node*>st;

    void traverse(Node* curr)
    {
        Node* previ;
        while(curr!=NULL)
        {
            if(curr->child)
            {
                if(curr->next)st.push(curr->next);
                curr->child->prev=curr;
                curr->next=curr->child;
                curr->child=NULL;
                traverse(curr->next);
            }
            previ=curr;
            curr=curr->next;
        }
        if(!st.empty())
        {
            Node* ptr=st.top();
            ptr->prev=previ;
            previ->next=ptr;
            st.pop();
            traverse(ptr);
        }
    }

    Node* flatten(Node* head) {        
        Node* curr=head;
        traverse(curr);
        return head;
    }
};