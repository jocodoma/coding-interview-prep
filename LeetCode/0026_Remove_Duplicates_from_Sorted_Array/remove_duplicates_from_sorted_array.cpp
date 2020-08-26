class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return twoPointers(nums);
    }

    // time complexity: O(n), space complexity: O(1)
    int twoPointers(vector<int>& nums){
        if(nums.empty())
            return 0;

        int i = 0;
        for(int j = 1; j < nums.size(); j++)
            if(nums[i] != nums[j])
                nums[++i] = nums[j];

        return i+1;
    }
};
