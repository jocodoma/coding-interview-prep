/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // time complexity: O(max(m,n)), space complexity: O(max(m,n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode *curr = &dummyHead;
        int carry = 0;

        while(l1 || l2){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;

            ListNode *node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry > 0){
            ListNode *node = new ListNode(carry);
            curr->next = node;
        }

        return dummyHead.next;
    }
};
