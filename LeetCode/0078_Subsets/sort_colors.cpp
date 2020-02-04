class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // return recursive(nums);  // backtracking
        return iterative(nums);
        // return bitManipulation(nums);
    }

private:
    // time complexity: O(n*2^n), space complexity: O(2^n)
    vector<vector<int>> recursive(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> sub;
        subsets(nums, 0, sub, ans);
        return ans;
    }

    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);
        for(int j = i; j < nums.size(); j++){
            sub.push_back(nums[j]);
            subsets(nums, j+1, sub, ans);
            sub.pop_back();
        }
    }

    // Using [1, 2, 3] as an example, the iterative process is like:
    // Initially, one empty subset [[]]
    // Adding 1 to [] => [[], [1]]
    // Adding 2 to [] and [1] => [[], [1], [2], [1, 2]]
    // Adding 3 to [], [1], [2] and [1, 2] => [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]

    // time complexity: O(n*2^n), space complexity: O(2^n)
    vector<vector<int>> iterative(vector<int>& nums){
        vector<vector<int>> subs = {{}};  // the inner brace initializes an int to 0, to ensure the inner for loop will be performed
        for(int num : nums){
            int n = subs.size();
            for(int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }

    // time complexity: O(), space complexity: O(2^n)
    vector<vector<int>> bitManipulation(vector<int>& nums){
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for(int i = 0; i < p; i++)
            for(int j = 0; j < n; j++)
                if((i >> j) & 1)
                    subs[i].push_back(nums[j]);

        return subs;
    }
};
