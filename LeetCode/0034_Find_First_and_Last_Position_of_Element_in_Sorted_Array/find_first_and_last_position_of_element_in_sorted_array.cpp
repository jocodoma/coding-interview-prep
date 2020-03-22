class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // return linearSearch(nums, target);
        return binarySearch(nums, target);
    }

    // time complexity: O(n), space complexity: O(1)
    vector<int> linearSearch(vector<int>& nums, int target){
        int first = -1, last = -1;
        if(nums.empty())
            return {first, last};

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > target)
                break;
            if(nums[i] == target){
                if(first < 0)
                    first = last = i;
                else
                    last = i;
            }
        }
        return {first, last};
    }

    // time complexity: O(log n)
    // space complexity: O(1) for iterative method, O(log n) for recursive method
    vector<int> binarySearch(vector<int>& nums, int target){
        if(nums.empty())
            return {-1, -1};

        // do binary search to look for the index of lower bound of the target value
        // int first = recursiveBinarySearch(nums, target, 0, nums.size()-1);
        int first = iterativeBinarySearch(nums, target, 0, nums.size()-1);
        if(first == nums.size() || nums[first] != target)
            return {-1, -1};
        // int last = recursiveBinarySearch(nums, target+1, first, nums.size()-1) - 1;
        int last = iterativeBinarySearch(nums, target+1, first, nums.size()-1) - 1;

        return {first, last};
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
