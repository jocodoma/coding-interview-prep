/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const lookupTable = {};
    for(let i = 0; i < nums.length; i++){
        const diff = target - nums[i];
        if(diff in lookupTable){
            return [lookupTable[diff], i];
        }
        lookupTable[nums[i]] = i;
    }
};
