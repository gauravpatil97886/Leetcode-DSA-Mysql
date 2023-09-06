public class Solution {
    public ListNode[] SplitListToParts(ListNode head, int k) {
        int length = 0;
        ListNode current = head;
        List<ListNode> parts = new List<ListNode>();

        while (current != null) {
            length++;
            current = current.next;
        }

        int base_size = length / k, extra = length % k;
        current = head;

        for (int i = 0; i < k; i++) {
            int part_size = base_size + (extra > 0 ? 1 : 0);
            ListNode part_head = null, part_tail = null;

            for (int j = 0; j < part_size; j++) {
                if (part_head == null) {
                    part_head = part_tail = current;
                } else {
                    part_tail.next = current;
                    part_tail = part_tail.next;
                }

                if (current != null) {
                    current = current.next;
                }
            }

            if (part_tail != null) {
                part_tail.next = null;
            }

            parts.Add(part_head);
            extra = System.Math.Max(extra - 1, 0);
        }

        return parts.ToArray();
    }
}