class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // return linearSearch(nums, target);
        return binarySearch(nums, target);
    }

    // time complexity: O(n), space complexity: O(1)
    vector<int> linearSearch(vector<int>& nums, int target){
        if(nums.empty()) return {-1, -1};

        int n = nums.size();
        int startIdx = -1, endIdx = -1;
        for(int i = 0; i < n; i++){
            if(target < nums[i]) break;
            if(nums[i] == target){
                if(startIdx < 0) startIdx = endIdx = i;
                else endIdx = i;
            }
        }
        return {startIdx, endIdx};
    }

    // time complexity: O(log n)
    // space complexity: O(1) for iterative method, O(log n) for recursive method
    vector<int> binarySearch(vector<int>& nums, int target){
        if(nums.empty())
            return {-1, -1};

        // do binary search to look for the index of lower bound of the target value

        // recursive
        // int first = recursiveBinarySearch(nums, target, 0, nums.size()-1);
        // if(first == nums.size() || nums[first] != target) return {-1, -1};
        // int end = recursiveBinarySearch(nums, target+1, first, nums.size()-1) - 1;

        // iterative
        int first = iterativeBinarySearch(nums, target, 0, nums.size()-1);
        if(first == nums.size() || nums[first] != target) return {-1, -1};
        int end = iterativeBinarySearch(nums, target+1, first, nums.size()-1) - 1;

        return {first, end};
    }

    int recursiveBinarySearch(vector<int>& nums, int target, int lo, int hi){
        if(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target)
                return recursiveBinarySearch(nums, target, mid+1, hi);
            else
                return recursiveBinarySearch(nums, target, lo, mid-1);
        }
        return lo;
    }

    int iterativeBinarySearch(vector<int>& nums, int target, int lo, int hi){
        while(lo <= hi){
            int mid = lo + ((hi - lo) >> 1);
            if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }
};
