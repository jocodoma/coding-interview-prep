#include <iostream>
#include <vector>

// Utility function to find minimum of two integers
// int min(int x, int y){ return (x < y) ? x : y; }

// sort and merge two subarrys
// first subarray is vec[l..m]
// second subarray is vec[m+1..r]
void merge(std::vector<int>& vec, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);  // temp arrays

    // copy data to temp arrays
    for(int i = 0; i < n1; i++)
        L[i] = vec[l+i];

    for(int i = 0; i < n1; i++)
        R[i] = vec[m+1+i];

    // merge the temp arrays back into vec[l..r]
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            vec[k++] = L[i++];
        else
            vec[k++] = R[j++];
    }

    // copy the remaining elements of L[] or R[], if there are any
    while(i < n1)
        vec[k++] = L[i++];

    while(j < n2)
        vec[k++] = R[j++];
}

void mergeSortIterative(std::vector<int>& vec){
    int n = vec.size();
    // divide the array into blocks of size bs
    // bs = 1, 2, 4, 8, 16, ...
    for(int bs = 1; bs < n; bs *= 2){  // size of block
        // bs = 1, i = 0, 2, 4, 6, 8, ...
        // bs = 2, i = 0, 4, 8, ...
        // bs = 4, i = 0, 8, ...
        for(int i = 0; i < n; i += bs*2){  // number of block
            // find ending point of left subarray
            // (bs+1) is starting point of right
            int l = i;
            int m = i + bs - 1;
            int r = std::min(i + bs*2 - 1, n-1);  // (n-1) will be chosen if remain elements are fewer than (m*2)
            merge(vec, l, m, r);
        }
    }
}

void mergeSortRecursive(std::vector<int>& vec, int l, int r){
    if(l < r){
        // same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // split into first and second halves, then sort and merge
        mergeSortRecursive(vec, l, m);
        mergeSortRecursive(vec, m+1, r);
        merge(vec, l, m, r);
    }
}

void printVector(std::vector<int> vec){
    for(const auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(){
    std::vector<int> input= {12, 11, 13, 5, 6, 7};

    std::cout << "Given array is \n";
    printVector(input);

    mergeSortRecursive(input, 0, input.size()-1);
    // mergeSortIterative(input);

    std::cout << "\nSorted array is \n";
    printVector(input);

    return 0;
}
