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
