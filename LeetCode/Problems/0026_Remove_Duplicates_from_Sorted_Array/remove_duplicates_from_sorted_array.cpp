#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return twoPointers(nums);
    }

    // time complexity: O(n), space complexity: O(1)
    int twoPointers(vector<int>& nums){
        if(nums.empty())
            return 0;

        int i = 0;
        for(int j = 1; j < nums.size(); j++)
            if(nums[i] != nums[j])
                nums[++i] = nums[j];

        return i+1;
    }

    int twoPointers2(vector<int>& nums){
        if(nums.empty())
            return 0;

        int i = 0;
        for(const auto& n : nums)
            if(nums[i] != n)
                nums[++i] = n;

        return i+1;
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
    vector<int> nums{1, 1, 2};

    cout << "Input: ";
    printVector(&nums, 3);

    Solution sol;
    int len = sol.removeDuplicates(nums);

    cout << "Output: ";
    printVector(&nums, len);

    return 0;
}
