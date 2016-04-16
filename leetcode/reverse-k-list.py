# Leetcode 25
# Reverse nodes in k-group

# Not optimal solution. O(k*n) due to additional passes over list to reverse groups.
# Groups should be reversed all at once instead of repositioning individual nodes.


# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        current = head
        new_head = None
        prev = None
        while current:
            count = 0
            count_node = current
            while count_node and count < k:
                count += 1
                count_node = count_node.next
            if count == k:
                swap = current
                for sc in range(k-1, 0, -1):
                    swap_start = swap.next
                    swap_prev = None
                    for i in range(sc):
                        tmp = swap.next.next
                        swap.next.next = swap
                        if swap_prev:
                            swap_prev.next = swap.next
                        swap_prev = swap.next
                        swap.next = tmp
                    swap = swap_start
                    print_list(swap)
                if prev:
                    prev.next = swap
                if not new_head:
                    new_head = swap
                prev = current
                current = current.next
            else:
                break
        return new_head or head

def print_list(head):
    current = head
    while current:
        print current.val,
        print ' ',
        current = current.next
    print

head = ListNode(1)
current = head
for i in range(2,5):
    current.next = ListNode(i)
    current = current.next

s = Solution()
print_list(head)
new_head = s.reverseKGroup(head, 4)
print_list(new_head)

