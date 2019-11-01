class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // return additionalVector(nums);
        return inPlaceVector(nums);
    }

    // time complexity: O(n), space complexity: O(n)
    void additionalVector(vector<int>& nums){
        if(nums.empty()) return;
        std::vector<int> result;
        int countZero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) result.push_back(nums[i]);
            else countZero++;
        }

        while(countZero--)
            result.push_back(0);

        for(int i = 0; i < nums.size(); i++)
            nums[i] = result[i];
    }

    // time complexity: O(n), space complexity: O(1)
    void inPlaceVector(vector<int>& nums){
        if(nums.empty()) return;
        int length = nums.size();
        int numNonZero = 0;
        for(int i = 0; i < length; i++)
            if(nums[i] != 0) nums[numNonZero++] = nums[i];

        for(int i = numNonZero; i < length; i++)
            nums[i] = 0;
    }
};
