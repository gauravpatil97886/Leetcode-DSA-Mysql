class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Convert linked list to array
        std::vector<ListNode*> arr;
        ListNode* current = head;
        while (current) {
            arr.push_back(current);
            current = current->next;
        }

        int n = arr.size();
        k %= n;

        if (k == 0) return head;

        // Rotate the array
        std::reverse(arr.begin(), arr.end());
        std::reverse(arr.begin(), arr.begin() + k);
        std::reverse(arr.begin() + k, arr.end());

        // Create a new linked list from the rotated array
        head = arr[0];
        current = head;
        for (int i = 1; i < n; ++i) {
            current->next = arr[i];
            current = current->next;
        }
        current->next = nullptr;

        return head;
    }
};