/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    // let maxSoFar = currMax = nums[0];
    // for(let i = 1; i< nums.length; i++){
    //     currMax = Math.max(currMax+nums[i], nums[i]);
    //     maxSoFar = Math.max(maxSoFar, currMax);
    // }
    // return maxSoFar;

    for(let i = 1; i < nums.length; i++){
        nums[i] = Math.max(nums[i], nums[i]+nums[i-1]);
    }
    return Math.max(...nums);
};
