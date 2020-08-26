class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return twoPointers(nums, val);
        // return swapValues(nums, val);
    }

    // time complexity: O(n), space complexity: O(1)
    int twoPointers(vector<int>& nums, int val){
        int i = 0;

        for(const auto& n : nums)
            if(n != val)
                nums[i++] = n;

        return i;
    }

    // time complexity: O(n), space complexity: O(1)
    int swapValues(vector<int>& nums, int val){
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            if(nums[l] == val)
                nums[l] = nums[r--];  // same as swap()
            else
                l++;
        }

        return l;
    }
};
