// more solutions on: https://leetcode.com/problems/majority-element/discuss/51612/C%2B%2B-6-Solutions

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // return bruteForce(nums);
        // return hashTable(nums);
        return sorting(nums);
    }

    // time complexity: O(n^2), space complexity: O(1)
    int bruteForce(vector<int>& nums){
        int majorityCount = nums.size()/2;
        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++)
                if(nums[i] == nums[j]) count++;

            if(count > majorityCount) return nums[i];
        }
        return -1;  // no majority element found
    }

    // time complexity: O(n), space complexity: O(n)
    int hashTable(vector<int>& nums){
        int majorityCount = nums.size()/2;
        std::unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.count(nums[i])) map[nums[i]]++;
            else map[nums[i]] = 1;
            if(map[nums[i]] > majorityCount) return nums[i];
        }
        return -1;  // no majority element found
    }

    // time complexity: O(nlogn), space complexity: O(1) if sorted in place
    int sorting(vector<int>& nums){
        std::nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
};
