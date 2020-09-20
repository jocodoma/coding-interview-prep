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
    ListNode* reverseList(ListNode* head) {
        // return recursion(head);
        return iteration(head);
    }

    // time complexity: O(n), space complexity: O(n) comes from stack space due to recursion
    ListNode* recursion(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *newRevHead = recursion(head->next);  // get the new head of reverse list
        ListNode *curRevTail = head->next;  // get the current tail of reversed list
        curRevTail->next = head;  // set the new tail of reverse list
        head->next = NULL;  // dereference
        return newRevHead;
    }

    // time complexity: O(n), space complexity: O(1)
    ListNode* iteration(ListNode* head){
        ListNode *newRevHead = NULL;
        while(head){
            ListNode* nextNode = head->next;
            head->next = newRevHead;
            newRevHead = head;
            head = nextNode;
        }
        return newRevHead;
    }
};
