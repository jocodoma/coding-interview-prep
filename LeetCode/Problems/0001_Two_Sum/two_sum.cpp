#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution(){};
    vector<int> twoSum(vector<int>& nums, int target) {
        // return bruteForce(nums, target);
        // return twoPassHashTable(nums, target);
        return onePassHashTable(nums, target);
    }

private:
    // time complexity: O(n^2)
    // space complexity: O(1)
    vector<int> bruteForce(vector<int>& nums, int target) {
        if (nums.empty())
            return {};

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(target == nums[i] + nums[j])
                    return {i, j};
            }
        }

        return {};  // No two sum solution, return an empty vector
    }

    // time complexity: O(2n) = O(n) due to two-pass
    // space complexity: O(n) due to hash table
    vector<int> twoPassHashTable(vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int,int> table;

        // build up a table
        for (int i = 0; i < n; i++) {
            table.insert({nums[i], i});
        }

        // check if diff is in the table
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if(table.count(diff) && i != table[diff])
                return {i, table[diff]};
        }

        return {};
    }

    // time complexity: O(n)
    // space complexity: O(n)
    vector<int> onePassHashTable(vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int,int> table;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if(table.count(diff))
                return {i, table[diff]};

            table[nums[i]] = i;  // same as table.insert({nums[i], i});
        }

        return {};
    }
};


int main() {
    Solution sol;

    vector<int> vec = {2,7,11,15};
    vec = sol.twoSum(vec, 9);
    cout << "Solution 1: {" << vec[0] << ", " << vec[1] << "}\n";

    vec = {3,2,4};
    vec = sol.twoSum(vec, 6);
    cout << "Solution 2: {" << vec[0] << ", " << vec[1] << "}\n";

    vec = {3,3};
    vec = sol.twoSum(vec, 6);
    cout << "Solution 3: {" << vec[0] << ", " << vec[1] << "}\n";

    return 0;
}
