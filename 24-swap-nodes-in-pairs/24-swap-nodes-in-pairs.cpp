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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next==nullptr) return head;
        ListNode *p, *q, *r;
        p = head;
        q = head->next;
        r = q->next;
        p->next = swapPairs(r);
        q->next = p;
        return q;
    }
};