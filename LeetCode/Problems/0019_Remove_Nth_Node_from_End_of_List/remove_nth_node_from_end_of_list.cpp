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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // return bruteForce(head, n);
        return twoPointers(head, n);
    }

private:
    // time complexity: O(2L) = O(L), (2L−n) operations
    // space complexity: O(1)
    ListNode* bruteForce(ListNode* head, int n){
        if(!head) return NULL;

        ListNode dummyHead(0);  // to handle if there's only one item in the list
        dummyHead.next = head;

        ListNode *curr = head;
        int len = 0;

        // find out the length of the list
        while(curr){
            curr = curr->next;
            len++;
        }

        // traverse to (n-1)-th node
        curr = &dummyHead;
        int i = len - n;
        while(i){
            curr = curr->next;
            i--;
        }

        // remove n-th node
        ListNode *unwanted = curr->next;
        ListNode *next = unwanted->next;
        curr->next = next;
        delete unwanted;

        return dummyHead.next;
    }

    // time complexity: O(L), space complexity: O(1)
    ListNode* twoPointers(ListNode* head, int n){
        if(!head) return NULL;

        ListNode dummyHead(0);
        dummyHead.next = head;

        // the distance between slow and fast is n
        ListNode *slow = &dummyHead, *fast = &dummyHead;
        for(int i = 0; i < n; i++)
            fast = fast->next;

        // traverse to (n-1)-th node
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        // remove n-th node
        ListNode *unwanted = slow->next;
        ListNode *next = unwanted->next;
        slow->next = next;
        delete unwanted;

        return dummyHead.next;
    }
};
