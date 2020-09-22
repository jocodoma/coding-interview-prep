#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        return solution(nums1, m, nums2, n);
    }

    // time complexity: O(n+m)
    // space complexity: O(1)
    void solution(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0)
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
};

// The nums is passed by constant pointer and cannot be changed by this function
void printVector(const vector<int>* nums){
    cout << "[";
    for(const auto& n : *nums){
        if(n != *nums->begin())
            cout << ", ";
        cout << n;
    }
    cout << "]";
}

int main(){
    int m = 3, n = 3;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    cout << "Input:\n";
    printVector(&nums1);
    cout << ",  m = " << m << "\n";
    printVector(&nums2);
    cout << ",  n = " << n << "\n";

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "\nOutput: ";
    printVector(&nums1);
    cout << "\n";

    return 0;
}
