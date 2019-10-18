class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//         int maxSoFar = nums[0];
//         int currMax = nums[0];
//         for(int i = 1; i < nums.size(); i++){
//             currMax = std::max(currMax+nums[i], nums[i]);
//             maxSoFar = std::max(maxSoFar, currMax);
//         }
//         return maxSoFar;

        for(int i = 1; i < nums.size(); i++){
            nums[i] = std::max(nums[i], nums[i]+nums[i-1]);
        }
        return *std::max_element(std::begin(nums), std::end(nums));
    }
};
