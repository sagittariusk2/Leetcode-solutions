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
        ListNode *p=head;
        ListNode *q=nullptr;
        if(p) q=p->next;
        
        while(q) {
            swap(q->val, p->val);
            if(q->next) {
                q = q->next->next;
            } else {
                q = q->next;
            }
            p = p->next->next;
        }
        
        return head;
    }
};