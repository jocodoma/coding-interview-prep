#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Approach 1: Brute Force
// Time:  O(n^2)
// Space: O(1)
class Solution_BruteForce {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < (int)nums.size(); i++) {
            for(int j = i + 1; j < (int)nums.size(); j++) {
                if(nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        return {};  // No two sum solution, return an empty vector
    }
};

// Approach 2: Two-pass Hash Table
// Time:  O(n)
// Space: O(n)
class Solution_TwoPassHashTable {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookupTable;
        for(int i = 0; i < (int)nums.size(); i++) {
            lookupTable.insert({nums[i], i});
        }
        for(int i = 0; i < (int)nums.size(); i++) {
            int diff = target - nums[i];
            if(lookupTable.count(diff)) {
                return {i, lookupTable[diff]};
            }
        }
        return {};
    }
};

// Approach 3: One-pass Hash Table
// Time:  O(n)
// Space: O(n)
class Solution_OnePassHashTable {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookupTable;
        for(int i = 0; i < (int)nums.size(); i++) {
          int diff = target - nums[i];
            if(lookupTable.count(diff)) {
                return {lookupTable[diff], i};
            }
            lookupTable[nums[i]] = i;  // same as lookupTable.insert({nums[i], i});
        }
        return {};
    }
};
