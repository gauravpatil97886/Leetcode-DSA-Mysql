class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Create a new node for each original node and insert it in between the original nodes.
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Assign random pointers for the cloned nodes.
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Separate the original and cloned lists.
        curr = head;
        Node* newHead = head->next;
        Node* clonedCurr = newHead;

        while (curr) {
            curr->next = clonedCurr->next;
            curr = curr->next;
            if (curr) {
                clonedCurr->next = curr->next;
                clonedCurr = clonedCurr->next;
            }
        }

        return newHead;
    }
};
