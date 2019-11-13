class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return bruteForce(nums, target);
        return binarySearch(nums, target);
    }

    // time complexity: O(n), space complexity: O(1)
    int bruteForce(vector<int>& nums, int target){
        if(nums.empty()) return -1;

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target) return i;

        return -1;
    }

    // time complexity: O(log n), space complexity: O(1)
    int binarySearch(vector<int>& nums, int target){
        if(nums.empty()) return -1;

        int lo = 0, hi = nums.size() - 1;

        // Find the index of the smallest value using binary search
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated
        // while(lo < hi){
        //     int mid = (lo + hi) / 2;
        //     if(nums[mid] > nums[hi]) lo = mid + 1;
        //     else hi = mid;
        // }

        // Reference: https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14419
        // Remember the array is sorted, except it might drop at one point
        // * If nums[0] <= nums[i], then nums[0..i] is sorted
        // * If nums[i] < nums[0], then nums[0..i] contains a drop, 
        //   and thus nums[i+1..end] is sorted and lies strictly between nums[0] and nums[i]
        // 
        // nums[0] <= target <= nums[i]
        //            target <= nums[i] < nums[0]
        //                      nums[i] < nums[0] <= target
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if((nums[0] <= target) ^ (target <= nums[mid]) ^ (nums[mid] < nums[0]))  // Bitwise XOR
                lo = mid + 1;
            else
                hi = mid;
        }

        return nums[lo] == target ? lo : -1;
    } 
};
