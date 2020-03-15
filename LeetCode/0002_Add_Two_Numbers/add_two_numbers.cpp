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
        return iterative(l1, l2);
        // return recursive(l1, l2);
    }

    ListNode* iterative(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);  // to avoid potential memory leak
        ListNode *curr = &dummyHead;
        int carry = 0;

        while(l1 || l2 || carry){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;

            ListNode *node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;

            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }

        return dummyHead.next;
    }

    ListNode* recursive(ListNode* l1, ListNode* l2){
        return helper(l1, l2, 0);
    }

    ListNode* helper(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2 && !carry)
            return NULL;

        ListNode dummyHead(0);  // to avoid potential memory leak
        ListNode *curr = &dummyHead;
        
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;

        ListNode *node = new ListNode(sum % 10);
        curr->next = node;
        curr = curr->next;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        curr->next = helper(l1, l2, carry);
        
        return dummyHead.next;
    }
};
