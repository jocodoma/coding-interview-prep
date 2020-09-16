class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // return twoArray(nums);
        // return twoPass(nums);
        return onePass(nums);
    }

    // time complexity: O(3n) = O(n), space complexity: O(2n) = O(n)
    vector<int> twoArray(vector<int>& nums){
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> result(n, 1);

        for(int i = 1; i < n; i++)
            left[i] = left[i-1] * nums[i-1];

        for(int i = n - 2; i >= 0; i--)
            right[i] = right[i+1] * nums[i+1];

        for(int i = 0; i < n; i++)
            result[i] = left[i] * right[i];

        return result;
    }

    // time complexity: O(2n) = O(n), space complexity: O(1)
    vector<int> twoPass(vector<int>& nums){
        int n = nums.size();
        int left = 1, right = 1;
        vector<int> result(n, 1);

        for(int i = 0; i < n; i++){
            result[i] *= left;
            left *= nums[i];
        }

        for(int i = 0; i < n; i++){
            result[n-1-i] *= right;
            right *= nums[n-1-i];
        }

        return result;
    }

    // time complexity: O(n), space complexity: O(1)
    vector<int> twoPass(vector<int>& nums){
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
