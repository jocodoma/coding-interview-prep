class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return backtracking(nums);
        // return nextPermutationSTL(nums);
        // return nextPermutation(nums);
    }

private:
    // time complexity: O(n!), space complexity: O(n) due to recursion
    vector<vector<int>> backtracking(vector<int>& nums){
        if(nums.empty()) return {{}};
        findPermutations(nums, 0);
        return result;
    }

    void findPermutations(vector<int> nums, int pos){
        if(pos == nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            std::swap(nums[pos], nums[i]);
            findPermutations(nums, pos + 1);
            // std::swap(nums[pos], nums[i]);  // no need if pass nums by value
        }
    }

    // time complexity: O(n!), space complexity: O(1)
    vector<vector<int>> nextPermutationSTL(vector<int>& nums){
        if(nums.empty()) return {{}};

        vector<vector<int>> result;
        int n = nums.size();
        int factorial = 1;
        while(n > 1){
            factorial *= n;
            n--;
        }
        for(int i = 0; i < factorial; i++){
            result.push_back(nums);
            std::next_permutation(nums.begin(), nums.end());
        }
        return result;
    }

    vector<vector<int>> nextPermutation(vector<int>& nums){
        if(nums.empty()) return {{}};
        vector<vector<int>> result;
        int f = findFactorial(nums.size());
        for(int i = 0; i < f; i++){
            result.push_back(nums);
            findNextPermutation(nums);
        }
        return result;
    }

    int findFactorial(int n){
        int f = 1;
        while(n > 1) f *= n--;
        return f;
    }

    // from 0031 - Next Permutation
    void findNextPermutation(vector<int>& nums){
        int n = nums.size();
        int i = 0, j = 0;

        for(i = n - 2; i >= 0; i--)
            if(nums[i] < nums[i+1])
                break;

        if(i < 0){  // handle edge cases
            std::reverse(nums.begin(), nums.end());
            return;
        }

        for(j = n - 1; j > i; j--)
            if(nums[i] < nums[j])
                break;

        std::swap(nums[i], nums[j]);  // swap nums[i] and nums[j]
        std::reverse(nums.begin() + i + 1, nums.end());  // reverse the sub-arry nums[i+1]
    }

    std::vector<std::vector<int>> result;
};
