/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head, *fast=head;
        while(slow and fast and fast->next) {
            if(fast->next)
                fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) {
                // find the length of cycle;
                fast=fast->next;
                int n=1;
                while(fast!=slow) {
                    n++;
                    fast = fast->next;
                }
                slow = head, fast=head;
                while(n--) {
                    fast = fast->next;
                }
                while(slow!=fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};