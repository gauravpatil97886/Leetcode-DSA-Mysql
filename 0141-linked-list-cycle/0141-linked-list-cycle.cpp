class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            // If the list has 0 or 1 nodes, there can't be a cycle.
            return false;
        }

        ListNode *tortoise = head;
        ListNode *hare = head;

        while (hare && hare->next) {
            tortoise = tortoise->next;       // Move one step.
            hare = hare->next->next;        // Move two steps.

            if (tortoise == hare) {
                // If the tortoise and hare meet, there is a cycle.
                return true;
            }
        }

        // If we reach the end of the list, there is no cycle.
        return false;
    }
};
