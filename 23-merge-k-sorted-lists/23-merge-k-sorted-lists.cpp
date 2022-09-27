/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    typedef pair<int, ListNode*> pl;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        ListNode* dummy = new ListNode(-1);
        priority_queue<pl, vector<pl>, greater<pl>>pq;

        for (auto i : lists)
        {
            if(i)
            pq.push({ i->val,i });
        }

        ListNode* curr = dummy;
        while (!pq.empty())
        {
            pl p = pq.top();
            pq.pop();
            curr->next = p.second;
            if (p.second->next)
                pq.push({ p.second->next->val,p.second->next });
            curr = curr->next;
        }
        return dummy->next;
    }
};