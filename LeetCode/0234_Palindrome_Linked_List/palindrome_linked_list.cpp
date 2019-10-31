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
    bool isPalindrome(ListNode* head) {
        // return useStack(head);
        return reverseHalfList(head);
    }

    // time complexity: O(n), space complexity: O(n)
    bool useStack(ListNode* head){
        std::stack<ListNode*> nodeStack;
        ListNode *node = head;
        while(node){
            nodeStack.push(node);
            node = node->next;
        }
        while(head){
            node = nodeStack.top(); nodeStack.pop();
            if(node->val != head->val) return false;
            head = head->next;
        }
        return true;
    }

    bool reverseHalfList(ListNode* head){
        if(!head || !head->next) return true;
        ListNode *fast = head, *slow = head;

        // find mid point
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *revHead = reverseList(slow->next);
        while(revHead != NULL){
            if(revHead->val != head->val) return false;
            revHead = revHead->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* newRevHead = NULL;
        while(head){
            ListNode *next = head->next;
            head->next = newRevHead;
            newRevHead = head;
            head = next;
        }
        return newRevHead;
    }
};
