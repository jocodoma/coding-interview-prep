#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        // return recursive(l1, l2);
        return iterative(l1, l2);
    }

private:
    // time complexity: O(max(m,n)), space complexity: O(max(m,n))
    ListNode* recursive(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);
        ListNode *node = &dummyHead;

        // base case
        if(!l1)
            return l2;

        if(!l2)
            return l1;

        // pick either l1 or l2
        if(l1->val < l2->val){
            node->next = l1;
            node = node->next;
            node->next = recursive(l1->next, l2);
        }
        else{
            node->next = l2;
            node = node->next;
            node->next = recursive(l1, l2->next);
        }

        return dummyHead.next;
    }

    // time complexity: O(max(m,n)), space complexity: O(1)
    ListNode* iterative(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);  // to avoid potential memory leak
        ListNode *currNode = &dummyHead;

        while(l1 && l2){
            ListNode *&nextNode = (l1->val < l2->val) ? l1 : l2;
            currNode->next = nextNode;
            nextNode = nextNode->next;
            currNode = currNode->next;
        }
        currNode->next = l1 ? l1 : l2;

        return dummyHead.next;
    }
};

string printList(ListNode* const head){
    string str;
    ListNode *curr = head;

    if(!curr)
        return str.append("Empty list");

    str.append("(");
    while(curr){
        str.append(std::to_string(curr->val));
        if(curr->next)
            str.append("->");
        curr = curr->next;
    }
    str.append(")");

    return str;
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
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    cout << "Input: " << printList(l1) << ", " << printList(l2) << "\n";

    Solution sol;
    ListNode *l3 = sol.mergeTwoLists(l1, l2);
    cout << "Output: " << printList(l3) << "\n";

    deleteList(&l3);  // since l3 = l1 + l2, delete l3 should also delete l1 and l2
    l1 = nullptr;
    l2 = nullptr;

    // cout << printList(l1) << "\n";
    // cout << printList(l2) << "\n";
    // cout << printList(l3) << "\n";

    return 0;
}
