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
        if(!head)return head;
        Node* th=head;
        Node* newList=new Node(head->val);
        Node* newHead=newList;        
        unordered_map<Node*,int>ump;
        unordered_map<int,Node*>ump2;
        int index=0;
        ump[th]=index;
        ump2[index]=newList;
        th=th->next;
        index++;
        while(th)
        {
            newList->next=new Node(th->val);
            ump2[index]=newList->next;
            ump[th]=index;
            th=th->next;
            index++;
            newList=newList->next;
        }
        newList=newHead;
        th=head;
        while(th)
        {
            if(th->random)
            {
                int randomIndexOld=ump[th->random];
                newList->random=ump2[randomIndexOld];
            }
            th=th->next;
            newList=newList->next;
        }
        return newHead;
    }
};