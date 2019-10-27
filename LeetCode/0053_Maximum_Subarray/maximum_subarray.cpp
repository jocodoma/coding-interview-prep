class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // return trackMaxSum(nums);
        return trackMaxSum2(nums);
    }

    int trackMaxSum(vector<int>& nums){
        if(nums.empty()) return 0;
        int currMaxSum = nums[0];
        int maxSumSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++){
            currMaxSum = std::max(currMaxSum+nums[i], nums[i]);
            maxSumSoFar = std::max(maxSumSoFar, currMaxSum);
        }
        return maxSumSoFar;
    }

    int trackMaxSum2(vector<int>& nums){
        if(nums.empty()) return 0;
        for(int i = 1; i < nums.size(); i++)
          nums[i] = std::max(nums[i], nums[i]+nums[i-1]);

        return *std::max_element(std::begin(nums), std::end(nums));
    }
};
