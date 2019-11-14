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

    // time complexity: O(log n), space complexity: O(1)
    vector<int> binarySearch(vector<int>& nums, int target){
        if(nums.empty()) return {-1, -1};

        int startIdx = -1, endIdx = -1;

        // find the lowest index of target
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        if(nums[lo] != target) return {startIdx, endIdx};
        startIdx = lo;

        // find the highest index of target (start from lo = startIdx)
        hi = nums.size() - 1;
        while(lo < hi){
            int sum = lo + hi;
            int mid = sum / 2;
            if(sum % 2 != 0) mid += 1;
            if(nums[mid] > target) hi = mid - 1;
            else lo = mid;
        }
        endIdx = hi;

        return {startIdx, endIdx};
    }
};
