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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);  // to avoid potential memory leak
        auto currNode = &dummyHead;

        while(l1 && l2){
            auto &nextNode = (l1->val < l2->val) ? l1 : l2;
            currNode->next = nextNode;
            nextNode = nextNode->next;
            currNode = currNode->next;
        }

        currNode->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};
