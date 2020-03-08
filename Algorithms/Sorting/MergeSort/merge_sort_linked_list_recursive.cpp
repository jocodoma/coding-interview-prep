#include <iostream>

// linked list node
struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node* merge(Node* a, Node* b){
    Node dummyHead(0);  // to avoid potential memory leak
    Node *tailNode = &dummyHead;

    while(a && b){
        Node *&nextNode = (a->data < b->data) ? a : b;
        tailNode->next = nextNode;
        nextNode = nextNode->next;
        tailNode = tailNode->next;
    }
    tailNode->next = a ? a : b;

    return dummyHead.next;

    // // base case
    // if(a == NULL)
    //     return b;
    // if(b == NULL)
    //     return a;

    // // pick either a or b
    // if(a->data < b->data){
    //     tailNode->next = a;
    //     tailNode = tailNode->next;
    //     tailNode->next = merge(a->next, b);
    // }
    // else{
    //     tailNode->next = b;
    //     tailNode = tailNode->next;
    //     tailNode->next = merge(a, b->next);
    // }
    // return dummyHead.next;
}

void frontBackSplit(Node* currHead, Node*& frontHead, Node*& backHead){
    Node *slow, *fast;
    slow = currHead;
    fast = currHead->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    // slow should be before the midpoint in the list
    frontHead = currHead;
    backHead = slow->next;

    slow->next = NULL;
}

void mergeSort(Node*& headNode){
    Node *head = headNode;
    Node *a, *b;

    // base case
    if(head == NULL || head->next == NULL)
        return;
    
    // split the list into two halves, a and b
    frontBackSplit(head, a, b);

    // recursively split each sublist
    mergeSort(a);
    mergeSort(b);

    // sort and merge the two list
    headNode = merge(a, b);
}

void printList(Node* node)
{
    while(node != NULL){
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
  
// function to insert a node at the beginging of the linked list
void push(Node** headNode, int newData){
    Node *newNode = new Node(newData);
    newNode->next = *headNode;
    *headNode = newNode;  // insert the new node to the head of list
}

void release(Node*& headNode){
    Node *currNode = headNode;
    while(currNode != NULL){
        Node *nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    headNode = NULL;
}

int main(){
    Node* a = NULL;

    // create a unsorted linked lists to test the functions
    // created lists shall be a: 2->3->20->5->10->15
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    std::cout << "Given array is \n";
    printList(a);

    // sort the above created Linked List
    mergeSort(a);
  
    std::cout << "\nSorted Linked List is: \n";
    printList(a);
  
    release(a);

    return 0;
}
