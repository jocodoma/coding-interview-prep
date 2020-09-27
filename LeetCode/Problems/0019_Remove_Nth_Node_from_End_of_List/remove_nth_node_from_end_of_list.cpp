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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        // return twoPass(head, n);
        return onePass(head, n);  // using two pointers
    }

private:
    // time complexity: O(2n) = O(n)
    // space complexity: O(1)
    ListNode* twoPass(ListNode* head, int n){
        if(!head)
            return nullptr;

        ListNode dummyHead(0);
        dummyHead.next = head;

        // find out the length of the list
        int length = 0;
        ListNode *curr = head;
        while(curr){
            length++;
            curr = curr->next;
        }

        // traverse to (n-1)-th node
        curr = &dummyHead;
        int i = length - n;
        while(i){
            curr = curr->next;
            i--;
        }

        // remove n-th node
        ListNode *unwanted = curr->next;
        curr->next = unwanted->next;
        delete(unwanted);

        return dummyHead.next;
    }

    // time complexity: O(n)
    // space complexity: O(1)
    ListNode* onePass(ListNode* head, int n){
        if(!head)
            return nullptr;

        ListNode dummyHead(0);
        dummyHead.next = head;

        ListNode *slow = &dummyHead, *fast = &dummyHead;

        // the distance between slow and fast is n
        for(int i = 0; i < n; i++)
            fast = fast->next;

        // traverse to (n-1)-th node
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        // remove n-th node
        ListNode *unwanted = slow->next;
        slow->next = unwanted->next;
        delete(unwanted);

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
            str.append(" -> ");
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
    int n = 2;
    ListNode *l = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    cout << "Input: " << printList(l) << ", n = " << n << "\n";

    Solution sol;
    sol.removeNthFromEnd(l, n);
    cout << "Output: " << printList(l) << "\n";

    deleteList(&l);
    // cout << printList(l) << "\n";

    return 0;
}
