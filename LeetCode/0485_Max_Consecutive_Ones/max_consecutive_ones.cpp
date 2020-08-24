class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // return bruteForce(nums);
        // return optimized1(nums);
        return optimized2(nums);
    }

    // time complexity: O(n^2)
    // space complexity: O(1)
    int bruteForce(vector<int>& nums){
        int maxCount = 0;

        for(int i = 0; i < nums.size(); i++){
            int count = 0;

            if(nums[i] == 0)
                continue;
            else
                count++;

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] == 1)
                    count++;
                else
                    break;
            }
            maxCount = (count > maxCount) ? count : maxCount;
        }
        return maxCount;
    }

    // time complexity: O(n)
    // space complexity: O(1)
    int optimized1(vector<int>& nums){
        int maxCount = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count ++;
                maxCount = (count > maxCount) ? count : maxCount;
            }
            else{
                count = 0;
            }
        }
        return maxCount;
    }

    // time complexity: O(n)
    // space complexity: O(1)
    int optimized2(vector<int>& nums){
        int maxCount = 0, count = 0;

        for(const auto& n : nums){
            if(n == 1)
                maxCount = std::max(maxCount, ++count);
            else
                count = 0;
        }
        return maxCount;
    }
};















class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //return bruteForce(nums);
        
        return optimized(nums);
    }
    
    int optimized(vector<int>& nums){
        int maxCount = 0, count = 0;
        
        for(auto n : nums){
            if(n == 1){
                maxCount = std::max(maxCount, ++count);
            }
            else{
                count = 0;
            }
        }
        
        return maxCount;
    }
    
    int bruteForce(vector<int>& nums){
        int maxCount = 0;
        
        // O(n^2)
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            
            if(nums[i] != 1)
                continue;
            else
                count++;
            
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] == 1)
                    count++;
                else
                    break;
            }
            maxCount = std::max(maxCount, count);
        }

        return maxCount;
    }
};
