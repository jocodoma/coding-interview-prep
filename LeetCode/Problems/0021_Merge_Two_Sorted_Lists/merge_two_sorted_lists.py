# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        mergeHead = currNode = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                currNode.next = l1
                l1 = l1.next
            else:
                currNode.next = l2
                l2 = l2.next
            currNode = currNode.next
        currNode.next = l1 or l2
        return mergeHead.next

#     def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
#         if not l1 or not l2:
#             return l1 or l2
#         if l1.val < l2.val:
#             l1.next = self.mergeTwoLists(l1.next, l2)
#             return l1
#         else:
#             l2.next = self.mergeTwoLists(l1, l2.next)
#             return l2

def printList(l) -> str:
    value = []
    while(l):
        value.append(l.val)
        l = l.next
    return('(' + '->'.join(map(str, value)) + ')')

l1 = ListNode(1, ListNode(2, ListNode(4)))
l2 = ListNode(1, ListNode(3, ListNode(4)))
print("Input: " + printList(l1) + ", " + printList(l2))

l3 = Solution().mergeTwoLists(l1, l2)
print("Output: " + printList(l3))
