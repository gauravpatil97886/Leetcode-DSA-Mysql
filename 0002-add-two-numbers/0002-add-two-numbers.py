class Solution:
    def addTwoNumbers(self, l1, l2):
        carry, dummy = 0, ListNode()
        current = dummy
        
        while l1 or l2 or carry:
            carry, total = divmod(carry + (l1.val if l1 else 0) + (l2.val if l2 else 0), 10)
            current.next = ListNode(total)
            current, l1, l2 = current.next, l1.next if l1 else None, l2.next if l2 else None
        
        return dummy.next
