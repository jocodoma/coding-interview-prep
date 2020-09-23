#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
public:
    Solution(){}

    // time complexity: O(max(m,n)), space complexity: O(max(m,n))
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2){
        // return recursive(l1, l2);
        return iterative(l1, l2);
    }

private:
    ListNode* iterative(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode dummyHead(0);
        ListNode *currNode = &dummyHead;  // to avoid potential memory leak

        while(l1 || l2 || carry){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;

            ListNode *node = new ListNode(sum % 10);
            currNode->next = node;
            currNode = currNode->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummyHead.next;
    }

    ListNode* recursive(ListNode* l1, ListNode* l2){
        return helper(l1, l2, 0);
    }

    ListNode* helper(ListNode* l1, ListNode* l2, int carry){

        if(!l1 && !l2 && !carry)
            return nullptr;

        ListNode dummyHead(0);
        ListNode *currNode = &dummyHead;  // to avoid potential memory leak

        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;

        ListNode *node = new ListNode(sum % 10);
        currNode->next = node;
        currNode = currNode->next;

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
        currNode->next = helper(l1, l2, carry);

        return dummyHead.next;
    }
};

void printList(ListNode* head){
    ListNode *node = head;

    if(!node){
        cout << "Empty list\n";
        return;
    }

    cout << "(";
    while(node){
        cout << node->val;
        if(node->next)
            cout << " -> ";
        node = node->next;
    }
    cout << ")\n";
}

void deleteList(ListNode** head){
    ListNode *curr = *head;
    ListNode *next;

    while(curr){
        next = curr->next;
        delete(curr);
        curr = next;
    }

    *head = nullptr;
}

int main(){

    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    cout << "Input: \n";
    printList(l1);
    printList(l2);

    Solution sol;
    ListNode *l3 = sol.addTwoNumber(l1, l2);

    cout << "\nOutput: \n";
    printList(l3);

    deleteList(&l1);
    deleteList(&l2);
    deleteList(&l3);
    printList(l1);
    printList(l2);
    printList(l3);

    return 0;
}
