#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return twoPointers(nums, val);
        // return swapValues(nums, val);
    }

    // time complexity: O(n), space complexity: O(1)
    int twoPointers(vector<int>& nums, int val){
        int i = 0;

        for(const auto& n : nums)
            if(n != val)
                nums[i++] = n;

        return i;
    }

    // time complexity: O(n), space complexity: O(1)
    int swapValues(vector<int>& nums, int val){
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            if(nums[l] == val)
                nums[l] = nums[r--];  // same as swap()
            else
                l++;
        }

        return l;
    }
};

// The nums is passed by constant pointer and cannot be changed by this function
void printVector(const vector<int>* nums, int len) {
    cout << "[";
    for(int i = 0; i < len; i++){
        if(i != 0)
            cout << ", ";
        // cout << nums->at(i);
        cout << (*nums)[i];
    }
    cout << "]\n";
}

// The nums is passed by constant reference and cannot be changed by this function
// void printVector(const vector<int>& nums, int len) {
//     cout << "[";
//     for(int i = 0; i < len; i++){
//         if(i != 0)
//             cout << ", ";
//         // cout << nums.at(i);
//         cout << nums[i];
//     }
//     cout << "]\n";
// }

int main(){
    vector<int> nums{3, 2, 2, 3};
    int val = 3;

    cout << "Input: ";
    printVector(&nums, 4);

    Solution sol;
    int len = sol.removeElement(nums, val);

    cout << "Output: ";
    printVector(&nums, len);

    return 0;
}
