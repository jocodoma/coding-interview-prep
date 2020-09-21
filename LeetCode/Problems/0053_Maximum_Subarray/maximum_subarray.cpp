#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return trackMaxSum(nums);
        // return trackMaxSum2(nums);
    }

    // time complexity: O(n), space complexity: O(1)
    int trackMaxSum(vector<int>& nums){
        if(nums.empty())
            return 0;

        int currMaxSum = nums[0];
        int maxSumSoFar = nums[0];

        for(int i = 1; i < nums.size(); i++){
            currMaxSum = std::max(currMaxSum+nums[i], nums[i]);
            maxSumSoFar = std::max(maxSumSoFar, currMaxSum);
        }

        return maxSumSoFar;
    }

    // using STL
    int trackMaxSum2(vector<int>& nums){
        if(nums.empty())
            return 0;

        for(int i = 1; i < nums.size(); i++)
            nums[i] = std::max(nums[i], nums[i]+nums[i-1]);

        return *std::max_element(std::begin(nums), std::end(nums));
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
    cout << "]\n";
}

// The nums is passed by constant reference and cannot be changed by this function
// void printVector(const vector<int>& nums){
//     cout << "[";
//     for(const auto& n : nums){
//         if(n != *nums.begin())
//             cout << ", ";
//         cout << n;
//     }
//     cout << "]";
// }

int main(){
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Input: ";
    printVector(&nums);

    Solution sol;
    cout << "Output: " << sol.maxSubArray(nums) << "\n";

    return 0;
}
