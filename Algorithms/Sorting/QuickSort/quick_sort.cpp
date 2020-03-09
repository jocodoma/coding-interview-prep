#include <iostream>
#include <vector>
#include <stack>

// a utility function to swap two elements
// void swap(int& a, int& b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// take last element as pivot
// place pivot element at correct position in sorted array
// all elements smaller than pivot to the left of pivot
// all elements greater than pivot to the right of pivot
int partition(std::vector<int>& vec, int l, int r){
    int pivot = vec[r];
    int i = l;  // initial index

    for(int j = l; j < r; j++){
        if(vec[j] < pivot)
            std::swap(vec[i++], vec[j]);  // increment index i, then swap
    }
    std::swap(vec[i], vec[r]);

    return i;
}

void quickSortIterative(std::vector<int>& vec){
    int n = vec.size();
    int l = 0;
    int r = n-1;

    // create an auxiliary stack
    std::stack<int> stack;
    stack.push(l);
    stack.push(r);

    while(!stack.empty()){
        r = stack.top(); stack.pop();
        l = stack.top(); stack.pop();

        int pi = partition(vec, l, r);

        // if there are elements on the left of pivot
        // then push left side to stack
        if(pi - 1 > l){
            stack.push(l);
            stack.push(pi-1);
        }

        // if there are elements on the right of pivot
        // then push right side to stack
        if(pi + 1 < r){
            stack.push(pi+1);
            stack.push(r);
        }
    }
}

// tail call optimization
// https://www.geeksforgeeks.org/tail-call-elimination/
// https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
// space complexity: O(n)
void quickSortRecursive_optimization(std::vector<int>& vec, int l, int r){
    while(l < r){
          int pi = partition(vec, l, r);
          quickSortRecursive_optimization(vec, l, pi-1);
          l = pi + 1;
    }
}

// space complexity: O(log n)
void quickSortRecursive_furtherOptimization(std::vector<int>& vec, int l, int r){
    while(l < r){
          int pi = partition(vec, l, r);

          if((pi - l) < (r - pi)){
              quickSortRecursive_furtherOptimization(vec, l, pi-1);
              l = pi + 1;
          }
          else{
              quickSortRecursive_furtherOptimization(vec, pi+1, r);
              r = pi - 1;
          }
    }
}

// l -> starting index
// r -> ending index
void quickSortRecursive(std::vector<int>& vec, int l, int r){
    if(l < r){
        // pi is partition index
        int pi = partition(vec, l, r);
        // vec[pi] is now at right place

        quickSortRecursive(vec, l, pi-1);  // sort elements befor pi
        quickSortRecursive(vec, pi+1, r);  // sort elements after pi
    }
}

void printVector(std::vector<int> vec){
    for(const auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

// driver code
int main(){
    std::vector<int> input = {10, 7, 8, 9, 1, 5};
    // std::vector<int> input = {4, 2, 6, 9, 2};
    // std::vector<int> input = {9, -3, 5, 2, 6, 8, -6, 1, 3};

    std::cout << "Given array is \n";
    printVector(input);

    quickSortRecursive(input, 0, input.size()-1);
    // quickSortRecursive_optimization(input, 0, input.size()-1);
    // quickSortRecursive_furtherOptimization(input, 0, input.size()-1);
    // quickSortIterative(input);

    std::cout << "\nSorted array is \n";
    printVector(input);

    return 0;
}
