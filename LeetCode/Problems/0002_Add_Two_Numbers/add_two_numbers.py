# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.__recursiveHelper(l1, l2, 0)

    def __recursiveHelper(self, l1, l2, carry) -> ListNode:
        if l1 == None and l2 == None and carry == 0:
            return None

        x = l1.val if l1 != None else 0
        y = l2.val if l2 != None else 0
        sum = x + y + carry
        carry = sum // 10  # '//' is a floor division operator
        new_node = ListNode(sum % 10)

        l1 = l1.next if l1 != None else None
        l2 = l2.next if l2 != None else None
        new_node.next = self.__recursiveHelper(l1,l2,carry)

        return new_node

def printList(l) -> str:
    value = []
    while(l):
        value.append(l.val)
        l = l.next
    return('(' + ' -> '.join(map(str, value)) + ')')

l1 = ListNode(2, ListNode(4, ListNode(3)))
l2 = ListNode(5, ListNode(6, ListNode(4)))
print("Input: " + printList(l1) + " + " + printList(l2))

l3 = Solution().addTwoNumbers(l1, l2)
print("Output: " + printList(l3))
