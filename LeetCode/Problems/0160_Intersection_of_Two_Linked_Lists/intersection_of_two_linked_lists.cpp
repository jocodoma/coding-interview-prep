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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // return bruteForce(headA, headB);
        // return hashTable(headA, headB);
        return twoPointersOneList(headA, headB);
    }

    // time complexity: O(nm), space complexity: O(1)
    ListNode *bruteForce(ListNode *headA, ListNode *headB){
        ListNode *currA, *currB;
        currA = headA;
        while(currA){
            currB = headB;
            while(currB){
                if(currA == currB) return currA;
                currB = currB->next;
            }
            currA = currA->next;
        }
        return NULL;
    }

    // time complexity: O(n+m), space complexity: O(m) or O(m)
    ListNode *hashTable(ListNode *headA, ListNode *headB){
        ListNode *currA = headA;
        ListNode *currB = headB;
        std::unordered_set<ListNode*> lookupTable;
        // build a map
        while(currA){
            lookupTable.insert(currA);
            currA = currA->next;
        }
        // lookup a map
        while(currB){
            if(lookupTable.count(currB)) return currB;
            currB = currB->next;
        }
        return NULL;
    }

    // combine two lists to create a new list (length = n + m)
    // time complexity: O(n+m), space complexity: O(1)
    ListNode *twoPointersOneList(ListNode *headA, ListNode *headB){
        ListNode *currA = headA, *currB = headB;
        while(currA != currB){
            currA = currA ? currA->next : headB;
            currB = currB ? currB->next : headA;
        }
        return currA;
    }
};
