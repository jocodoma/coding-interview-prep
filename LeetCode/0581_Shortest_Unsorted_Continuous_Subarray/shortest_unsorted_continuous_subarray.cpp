class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // return sortAndCheck(nums);
        return checkFromBeginAndEnd(nums);
    }

    // time complexity: O(nlogn), space complexity: O(n)
    int sortAndCheck(vector<int>& nums){
        int n = nums.size();
        if(n == 0 || n == 1) return 0;

        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        int indexStart = 0, indexEnd = n - 1;
        while((indexStart < n) && (nums[indexStart] == sortedNums[indexStart])) indexStart++;
        while((indexEnd > indexStart) && (nums[indexEnd] == sortedNums[indexEnd])) indexEnd--;

        return indexEnd - indexStart + 1;
    }

    // time complexity: O(n), space complexity: O(1)
    int checkFromBeginAndEnd(vector<int>& nums){
        int n = nums.size();
        if(n == 0 || n == 1) return 0;

        int leftMaxSoFar = nums[0], rightMinSoFar = nums[n-1];
        int indexStart = -1, indexEnd = -2;

        for(int i = 0; i < n; i++){
            leftMaxSoFar = std::max(leftMaxSoFar, nums[i]);
            if(nums[i] < leftMaxSoFar) indexEnd = i;

            rightMinSoFar = std::min(rightMinSoFar, nums[n-1-i]);
            if(nums[n-1-i] > rightMinSoFar) indexStart = n-1-i;
        }

        return indexEnd - indexStart + 1;
    }
};
