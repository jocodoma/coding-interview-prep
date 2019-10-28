// Solution 1 - Two stacks
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        dataStack.push(x);
        if(minStack.empty()) minStack.push(x);
        else minStack.push(std::min(minStack.top(), x));
    }
    
    void pop() {
        if(dataStack.empty()) return;
        dataStack.pop();
        minStack.pop();
    }
    
    int top() {
        if(dataStack.empty()) return 0;
        return dataStack.top();
    }
    
    int getMin() {
        if(minStack.empty()) return 0;
        return minStack.top();
    }

private:
    std::stack<int> dataStack;
    std::stack<int> minStack;
};

// Solution 2 - Two vectors
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        dataVector.push_back(x);
        if(minVector.empty()) return minVector.push_back(x);
        else minVector.push_back(std::min(minVector.back(), x));
    }
    
    void pop() {
        if(dataVector.empty()) return;
        dataVector.pop_back();
        minVector.pop_back();
    }
    
    int top() {
        if(dataVector.empty()) return 0;
        return dataVector.back();
    }
    
    int getMin() {
        if(minVector.empty()) return 0;
        return minVector.back();
    }

private:
    std::vector<int> dataVector;
    std::vector<int> minVector;
};

// Solution 3 - Linked list
// Definition for singly-linked list.
struct ListNodeMinStack {
    int val;
    int minValSoFar;
    ListNodeMinStack *next;
    ListNodeMinStack(int x, int y) : val(x), minValSoFar(y), next(NULL) {}
};
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        ListNodeMinStack *newNode = new ListNodeMinStack(x, x);
        if(!head){
            head = newNode;
        }
        else{
            // track and update the minimum value in the list so far
            newNode->minValSoFar = std::min(head->minValSoFar, x);
            newNode->next = head;
            head = newNode;
        }
    }
    
    void pop() {
        if(!head) return;
        // delete head
        ListNodeMinStack *tmpNode = head;
        head = head->next;
        delete tmpNode;
    }
    
    int top() {
        if(!head) return 0;
        return head->val;
    }
    
    int getMin() {
        if(!head) return 0;
        return head->minValSoFar;
    }

private:
    ListNodeMinStack *head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
