class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // return BruteForce(nums);
        return onePass(nums);
    }

    // Brute Force
    // time complexity: O(n!), space complexity: O(n)

    // In this approach, we find out every possible permutation of list formed by
    // the elements of the given array and find out the permutation which is
    // just larger than the given one. But this one will be a very naive approach,
    // since it requires us to find out every possible permutation which will take
    // really long time and the implementation is complex. Thus, this approach
    // is not acceptable at all. Hence, we move on directly to the correct approach.

    // Reference: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    // time complexity: O(n), space complexity: O(1)
    void onePass(vector<int>& nums){
        int n = nums.size();
        int i = 0, j = 0;

        // find the largest index i, such that nums[i] < nums[i+1]
        for(i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1])
                break;
        }

        // handle edge cases
        // e.g. n = 0, n = 1, n = 2 but two numbers are the same
        if(i < 0){
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // find the largest index j, where j > i, such that nums[i] < nums[j]
        for(j = n - 1; j > i; j--){
            if(nums[i] < nums[j])
                break;
        }

        // swap nums[i] and nums[j]
        std::swap(nums[i], nums[j]);

        // reverse the sub-arry nums[i+1]
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
