class Solution {
public:
    bool canJump(vector<int>& nums) {
        // return backtracking(nums);
        // return greedy(nums);
        return maxIndex(nums);
    }

private:
    // time complexity: O(2^n), space complexity: O(n)
    bool backtracking(vector<int>& nums){
        if(nums.empty()) return false;
        return goBacktracking(0, nums);
    }

    bool goBacktracking(int idx, vector<int>& nums){
        int lastIdx = nums.size() - 1;

        if(idx == lastIdx) return true;
        if(idx > lastIdx || nums[idx] == 0) return false;

        int maxJump = idx + nums[idx];
        for(int nextIdx = idx + 1; nextIdx <= maxJump; nextIdx++){
            if(goBacktracking(nextIdx, nums))
                return true;
        }
        return false;
    }

    // To Do
    // * Dynamic Programming - Top down
    // * Dynamic Programming - Bottom up

    // Greedy
    // Looking from the start and selecting the locally optimum in the hope of reaching global optimum
    // time complexity: O(n), space complexity: O(1)
    bool greedy(vector<int>& nums){
        int n = nums.size(), maxJump = 0;
        for(int i = 0;i < n; i++){
            if(maxJump < i) return false;
            maxJump = std::max(maxJump, i + nums[i]);
        }
        return true;
    }

    // Greedy improvement
    // iterate and update the maximal index that I can reach
    // time complexity: O(n), space complexity: O(1)
    bool maxIndex(vector<int>& nums){
        if(nums.empty()) return false;
        int lastIdx = nums.size() - 1;
        int dis = 0;
        for (int i = 0; i <= dis; i++) {
            dis = std::max(dis, i + nums[i]);
            if(dis >= lastIdx) return true;
        }
        return false;
    }
};
