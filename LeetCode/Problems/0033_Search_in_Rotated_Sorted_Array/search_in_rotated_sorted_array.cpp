#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return bruteForce(nums, target);
        return binarySearch(nums, target);
        // return binarySearchXor(nums, target);
    }

private:
    // time complexity: O(n), space complexity: O(1)
    int bruteForce(vector<int>& nums, int target){
        if(nums.empty())
            return -1;

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target)
                return i;

        return -1;
    }

    // time complexity: O(log n), space complexity: O(1)
    int binarySearch(vector<int>& nums, int target){
        // case 1 - typical binary search
        // nums[l] <= nums[mid] <= nums[r]
        // [l .. mid - 1] && [mid + 1 .. r] are both sorted

        // case 2 - mid before pivot
        // -> nums[mid] > nums[r]
        // [l .. mid - 1] is sorted
        // [mid + 1 .. r] contains a drop

        // case 3 - mid after pivot
        // -> nums[mid] < nums[l]
        // [l .. mid - 1] contains a drop
        // [mid + 1 .. r] is sorted

        if(nums.empty())
            return -1;

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            // int mid = (l + r) / 2;  may have overflow
            int mid = (r - l) / 2 + l;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] > nums[r])
                if(nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            else
                if(nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
        }

        return -1;
    }

    // time complexity: O(log n), space complexity: O(1)
    int binarySearchXor(vector<int>& nums, int target){
        // Find the index of the smallest value using binary search
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated
        // while(lo < hi){
        //     int mid = (lo + hi) / 2;
        //     if(nums[mid] > nums[hi])
        //         lo = mid + 1;
        //     else
        //         hi = mid;
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

        if(nums.empty())
            return -1;

        int lo = 0;
        int hi = nums.size() - 1;

        while(lo < hi){
            // int mid = (l + r) / 2;  may have overflow
            int mid = (hi - lo) / 2 + lo;

            // [mid .. hi] contains no drop
            if((nums[0] <= target) ^ (target <= nums[mid]) ^ (nums[mid] < nums[0]))  // bitwise XOR
                lo = mid + 1;

            // [lo .. mid] contains no drop
            else
                hi = mid;
        }

        return nums[lo] == target ? lo : -1;
    }
};

int main(){
    vector<int> nums;
    int target = 0;
    Solution sol;

    nums = {4,5,6,7,0,1,2};
    target = 0;
    cout << "Output: " << sol.search(nums, target) << "\n";

    nums = {4,5,6,7,0,1,2};
    target = 3;
    cout << "Output: " << sol.search(nums, target) << "\n";

    nums = {1};
    target = 0;
    cout << "Output: " << sol.search(nums, target) << "\n";

    return 0;
}
