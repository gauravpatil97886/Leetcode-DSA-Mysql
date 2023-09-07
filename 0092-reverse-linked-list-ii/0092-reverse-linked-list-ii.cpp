class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;

        // Move pre and cur to their positions
        for (int i = 1; i < m; i++) {
            pre = pre->next;
            cur = cur->next;
        }

        // Reverse the sublist
        for (int i = m; i < n; i++) {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }

        return dummy->next;
    }
};
