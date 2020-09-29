#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(){}
    vector<int> productExceptSelf(vector<int>& nums){
        // return twoArray(nums);
        // return twoPass(nums);
        return onePass(nums);
    }

private:
    // time complexity: O(3n) = O(n)
    // space complexity: O(2n) = O(n)
    vector<int> twoArray(vector<int>& nums){
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> result(n, 1);

        // L array
        for(int i = 1; i < n; i++)
            left[i] = left[i-1] * nums[i-1];

        // R array
        for(int i = n - 2; i >= 0; i--)
            right[i] = right[i+1] * nums[i+1];

        // result array
        for(int i = 0; i < n; i++)
            result[i] = left[i] * right[i];

        return result;
    }

    // time complexity: O(2n) = O(n)
    // space complexity: O(1)
    vector<int> twoPass(vector<int>& nums){
        int n = nums.size();
        int left = 1, right = 1;
        vector<int> result(n, 1);

        // result = left (L array)
        for(int i = 0; i < n; i++){
            result[i] *= left;
            left *= nums[i];
        }

        // result *= right (R array)
        for(int i = 0; i < n; i++){
            result[n-1-i] *= right;
            right *= nums[n-1-i];
        }

        return result;
    }

    // time complexity: O(n), space complexity: O(1)
    vector<int> onePass(vector<int>& nums){
        int n = nums.size();
        int left = 1, right = 1;
        vector<int> result(n, 1);

        for(int i = 0; i < n; i++){
            result[i] *= left;
            result[n-1-i] *= right;
            left *= nums[i];
            right *= nums[n-1-i];
        }

        return result;
    }
};

// nums is passed by constant reference and cannot be changed by this function
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

int main(){
    vector<int> input({1,2,3,4});
    cout << "Input: " << printVector(input) << "\n";

    Solution sol;
    vector<int> output = sol.productExceptSelf(input);
    cout << "Output: " << printVector(output) << "\n";

    return 0;
}
