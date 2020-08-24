class Solution {
public:
    int findNumbers(vector<int>& nums) {
        // return solution1(nums);
        return solution2(nums);
    }

    // time complexity: O(nm), where n is the size of input, m is the max number of digits
    // space complexity: O(1)
    int solution1(vector<int>& nums){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int numDigits = 0;
            int num = nums[i];
            
            do {
                num /= 10;
                numDigits++;
            } while(num != 0);

            if(numDigits % 2 == 0)
                count++;
        }
        return count;
    }

    // time complexity: O(n)
    // space complexity: O(1)    
    int solution2(vector<int>& nums){
        int count = 0;

        for(const auto& n : nums)
            // Question constraint: 1 <= nums[i] <= 10^5
            if((9 < n && n < 100) || (999 < n && n < 10000) || n == 100000)
                count++;

        return count;
    }
};
