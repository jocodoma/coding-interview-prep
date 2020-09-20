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
    bool hasCycle(ListNode *head) {
        // return checkVisitedNode(head);
        return twoPointers(head);
        // return twoPointers2(head);
    }

    // hashset - space complexity O(n)
    bool checkVisitedNode(ListNode *head){
        std::unordered_set<ListNode*> visitedNodeSet;
        while(head){
            if(visitedNodeSet.count(head)) return true;
            visitedNodeSet.insert(head);
            head = head->next;
        }
        return false;
    }

    // two pointers at different speed - space complexity O(1)
    bool twoPointers(ListNode *head){
        if(!head) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            if(slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }

    bool twoPointers2(ListNode *head){
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
