#include <iostream>
#include <vector>
#include <stack>

// a utility function to swap two elements
// void swap(int& a, int& b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// take the first element as pivot
// place pivot element at correct position in sorted array
// all elements smaller than pivot to the left of pivot
// all elements greater than pivot to the right of pivot
// using Hoare's partition scheme
int partition_hoare(std::vector<int>& vec, int l, int r){
    int pivot = vec[l];
    int i = l, j = r;  // initial index

    while(i < j){
        // find leftmost element greater than or equal to pivot
        while(vec[i] < pivot)
            i++;

        // find rightmost element smaller than or equal to pivot
        while(vec[j] > pivot)
            j--;

        if(i < j)
            std::swap(vec[i], vec[j]);
    }

    return j;
}

// take last element as pivot
// place pivot element at correct position in sorted array
// all elements smaller than pivot to the left of pivot
// all elements greater than pivot to the right of pivot
// using Lomuto partition scheme
int partition_lomuto(std::vector<int>& vec, int l, int r){
    int pivot = vec[r];
    int i = l;  // initial index

    for(int j = l; j < r; j++){
        if(vec[j] < pivot)
            std::swap(vec[i++], vec[j]);  // increment index i, then swap
    }
    std::swap(vec[i], vec[r]);

    return i;
}

// pick a random index for the random pivot
void pickRandomIndex(std::vector<int>& vec, int l, int r){
    int pi = l + rand() % (r-l+1);  // choose a random index between [l, r]
    std::swap(vec[pi], vec[r]);     // (Lomuto) swap the end element with element present at random index
    // std::swap(vec[pi], vec[l]);     // (Hoare's) swap the first element with element present at random index
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

        int pi = partition_lomuto(vec, l, r);

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
          int pi = partition_lomuto(vec, l, r);
          quickSortRecursive_optimization(vec, l, pi-1);
          l = pi + 1;
    }
}

// a recursive call is only for the smaller part after partition
// space complexity: O(log n)
void quickSortRecursive_furtherOptimization(std::vector<int>& vec, int l, int r){
    while(l < r){
          int pi = partition_lomuto(vec, l, r);

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
        pickRandomIndex(vec, l, r);            // pick a random index for randomized partition
        int pi = partition_lomuto(vec, l, r);  // pick the last element as pivot
        // int pi = partition_hoare(vec, l, r);   // pick the last element as pivot
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
    // std::vector<int> input = {9, 8, 7, 6, 5, 4, 3, 2, 1};

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
