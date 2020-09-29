#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution{
public:
    Solution(){}

    void mergeSort_recursive(ListNode** headNode){
        ListNode *head = *headNode;
        ListNode *a, *b;

        // base case
        if(!head || !head->next)
            return;

        // split the list into two halves, a and b
        frontBackSplit(head, &a, &b);

        // recursively split each sublist
        mergeSort_recursive(&a);
        mergeSort_recursive(&b);

        // sort and merge two sublists
        * headNode = merge(a, b);
    }

private:
    void frontBackSplit(ListNode* currHead, ListNode** frontHead, ListNode** backHead){
        ListNode *slow, *fast;

        slow = currHead;
        fast = currHead->next;

        while(fast){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
        }

        // slow should be before or at the midpoint in the list
        *frontHead = currHead;
        *backHead = slow->next;

        slow->next = nullptr;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        return merge_recursive(l1, l2);
        // return merge_iterative(l1, l2);
    }

    ListNode* merge_recursive(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);  // to avoid potential memory leak
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
            node->next = merge_recursive(l1->next, l2);
        }
        else{
            node->next = l2;
            node = node->next;
            node->next = merge_recursive(l1, l2->next);
        }

        return dummyHead.next;
    }

    ListNode* merge_iterative(ListNode* l1, ListNode* l2){
        ListNode dummyHead(0);
        ListNode *node = &dummyHead;

        while(l1 && l2){
            ListNode *&nextNode = (l1->val < l2->val) ? l1 : l2;
            node->next = nextNode;

            nextNode = nextNode->next;
            node = node->next;
        }

        node->next = l1 ? l1 : l2;

        return dummyHead.next;
    }
};

string printList(ListNode* const head){
    string str;
    ListNode *node = head;

    if(!node)
        return str.append("Empty");

    str.append("(");
    while(node){
        str.append(std::to_string(node->val));
        if(node->next)
            str.append("->");
        node = node->next;
    }
    str.append(")");

    return str;
}

void deleteList(ListNode** head){
    ListNode *curr = *head;
    ListNode *next;

    while(curr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    *head = nullptr;
}

int main(){
    // create a unsorted linked lists to test the functions
    // created lists shall be a: 2->3->20->5->10->15
    ListNode *l = new ListNode(2, new ListNode(3, new ListNode(20, new ListNode(5, new ListNode(10, new ListNode(15))))));
    cout << "Given linked list is " << printList(l) << "\n";

    Solution sol;
    sol.mergeSort_recursive(&l);
    cout << "Sorted linked list is " << printList(l) << "\n";

    deleteList(&l);

    return 0;
}
