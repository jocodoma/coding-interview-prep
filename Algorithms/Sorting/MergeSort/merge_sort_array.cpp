#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(){}

    void mergeSortRecursive(vector<int>& nums){
        mergeSortRecursiveHelper(nums, 0, nums.size()-1);
    }

    void mergeSortIterative(vector<int>& nums){
        int n = nums.size();
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
                merge(nums, l, m, r);
            }
        }
    }

private:
    void mergeSortRecursiveHelper(vector<int>& nums, int l, int r){
        if(l < r){
            // same as (l+r)/2, but avoids overflow for large l and r
            int m =  l + (r - l) / 2;

            // split into first and second halves, then sort and finally merge
            mergeSortRecursiveHelper(nums, l, m);
            mergeSortRecursiveHelper(nums, m+1, r);
            merge(nums, l, m, r);
        }
    }

    // Utility function to find minimum of two integers
    // int min(int x, int y){ return (x < y) ? x : y; }

    // sort and merge two subarrays
    // first subarray is nums[l..m]
    // second subarray is nums[m+1..r]
    void merge(vector<int>& nums, int l, int m, int r){
        int n1 = m - l + 1;
        int n2 = r -  m;
        vector<int> L(n1), R(n2);  // temp arrays

        // copy data to temp arrays
        for(int i = 0; i < n1; i++)
            L[i] = nums[l+i];

        for(int i = 0; i < n2; i++)
            R[i] = nums[m+1+i];

        // merge the temp arrays back into nums[l..r]
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2)
            nums[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

        // copy the remaining elements of L[] or R[], if there are any
        while(i < n1)
            nums[k++] = L[i++];

        while(j < n2)
            nums[k++] = R[j++];
    }
};

string printVector(const vector<int>& nums){
    string str;

    str.append("[");
    for(const auto& n : nums){
        if(n != *nums.begin())
            str.append(", ");
        str.append(std::to_string(n));
    }
    str.append("]");

    return str;
}

// driver code
int main(){
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    cout << "Given array is " << printVector(nums) << "\n";

    Solution sol;
    sol.mergeSortRecursive(nums);
    // sol.mergeSortIterative(nums);
    cout << "Sorted array is " << printVector(nums) << "\n";

    return 0;
}
