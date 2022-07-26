/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>originalToRandom;
        unordered_map<Node*,Node*>originalReference;
        Node* dummy=new Node(-1);
        Node* newHead=dummy;
        while(head){
            Node* temp=new Node(head->val);            
            dummy->next=temp;
            originalToRandom[head]=head->random;
            originalReference[head]=temp;
            dummy=dummy->next;
            head=head->next;
        }
        for(auto it:originalToRandom)
        {
            Node* ogNode=it.first;
            Node* ogRandom=it.second;
            originalReference[it.first]->random=originalReference[it.second];
        }
        return newHead->next;
    }
};