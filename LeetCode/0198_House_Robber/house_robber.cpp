class Solution {
public:
    int rob(vector<int>& nums) {
        // return maxArray(nums);
        return maxVars(nums);
    }

    // time complexity: O(n), space complexity: O(n)
    int maxArray(vector<int>& nums){
        int length = nums.size();
        if(length == 0) return 0;
        if(length == 1) return nums[0];
        if(length == 2) return std::max(nums[0], nums[1]);

        int maxArray[length];
        maxArray[0] = nums[0];
        maxArray[1] = std::max(maxArray[0], nums[1]);
        for(int i = 2; i < length; i++)
            maxArray[i] = std::max(maxArray[i-1], nums[i] + maxArray[i-2]);

        return maxArray[length-1];
    }

    // time complexity: O(n), space complexity: O(1)
    int maxVars(vector<int>& nums){
        if(nums.empty()) return 0;
        int length = nums.size();
        int preNotAdjMax = 0;  // [i-2]
        int currMax = 0;  // [i-1]
        for(const auto& num : nums){
            int nextMax = std::max(currMax, num + preNotAdjMax);
            preNotAdjMax = currMax;
            currMax = nextMax;
        }
        return currMax;
    }
};
