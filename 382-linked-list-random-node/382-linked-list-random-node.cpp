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
    
    vector<int> v1;
    
    Solution(ListNode* head) {
        while(head) {
            v1.push_back(head->val);
            head=head->next;
        }
        srand(time(0));
    }
    
    int getRandom() {
        int x = rand();
        int i = x%v1.size();
        return v1[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */