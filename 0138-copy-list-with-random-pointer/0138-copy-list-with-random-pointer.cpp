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
        Node* h = head;
        while (h)
        {
            Node* nh = new Node(h->val);
            nh->next=h->next;
            h->next=nh;
            h=nh->next;
        }
        Node* th = head;
        
        while(th and th->next)
        {
            if(th->random){
                th->next->random=th->random->next;
            }
            th=th->next->next;
        }//copy all randoms
        Node* ans=nullptr;
        Node* nth=nullptr;
        th=head;
        while(th and th->next)
        {
            if(ans==nullptr)
            {
                ans=th->next;
                nth=th->next;
            }
            else{
                nth->next=th->next;
                nth=nth->next;
            }
            th->next=th->next->next;
            th=th->next;
        }
        
        return ans;
    }
};