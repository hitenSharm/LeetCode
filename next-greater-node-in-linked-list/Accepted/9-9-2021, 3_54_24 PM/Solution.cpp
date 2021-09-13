// https://leetcode.com/problems/next-greater-node-in-linked-list

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
    vector<int> nextLargerNodes(ListNode* head) {
        int n=0;
        ListNode* tmp=head;
        while(tmp)
        {
            n++;
            tmp=tmp->next;
        }
        vector<int>ans(n,0);
        stack<pair<int,int>>st;
        int i=0;
        while(head)
        {
            while(!st.empty() and head->val>st.top().second)
            {
                ans[st.top().first]=head->val;
                st.pop();
            }
            st.push({i,head->val});
            i++;
            head=head->next;
        }
        return ans;
    }
};