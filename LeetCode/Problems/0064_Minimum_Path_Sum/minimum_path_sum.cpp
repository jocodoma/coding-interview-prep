class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return dp1(grid);
        // return dp2(grid)
        // return dp3(grid)
    }

    // Brute Force: Overlapping Subproblems
    // // Reference: https://www.geeksforgeeks.org/min-cost-path-dp-6/
    // It can be simply done by recursion, but will computes the same subproblems again and again.
    // Thus, the time complexity will be exponential and it's terribly slow.

    // Dynamic Programming method
    // Reference: https://leetcode.com/problems/minimum-path-sum/discuss/23457/C%2B%2B-DP
    // This is a typical DP problem.
    // Suppose the minimum path sum of arriving at point (i, j) is S[i][j],
    // then the state equation is S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j].

    // time complexity: O(mn), space complexity:O(mn)
    int dp1(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> sum(m, std::vector<int>(n, grid[0][0]));

        for(int i = 1; i < m; i++)
            sum[i][0] = sum[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++)
            sum[0][j] = sum[0][j-1] + grid[0][j];

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                sum[i][j] = std::min(sum[i-1][j], sum[i][j-1]) + grid[i][j];

        return sum[m-1][n-1];
    }

    // As can be seen, each time when we update sum[i][j],
    // we only need sum[i - 1][j] (at the current column) and sum[i][j - 1] (at the left column).
    // So we need not maintain the full m*n matrix.
    // Maintaining two columns is enough and now we have the following code.

    // time complexity: O(mn), space complexity: O(2n) = O(n)
    int dp2(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> pre(n, grid[0][0]), cur(n, grid[0][0]);
        for(int j = 1; j < n; j++)
            pre[j] = pre[j-1] + grid[0][j];

        for(int i = 1; i < m; i++){
            cur[0] = pre[0] + grid[i][0];
            for(int j = 1; j < n; j++)
                cur[j] = std::min(pre[j], cur[j-1]) + grid[i][j];

            std::swap(pre, cur);
        }

        return pre[n-1];
    }

    // Further inspecting the above code,
    // it can be seen that maintaining pre is for recovering pre[i],
    // which is simply cur[i] before its update. So it is enough to use only one vector.
    // Now the space is further optimized and the code also gets shorter.

    // time complexity: O(mn), space complexity: O(n)
    int dp3(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> cur(n, grid[0][0]);
        for(int j = 1; j < n; j++)
            cur[j] = cur[j-1] + grid[0][j];

        for(int i = 1; i < m; i++){
            cur[0] += grid[i][0];
            for(int j = 1; j < n; j++)
                cur[j] = std::min(cur[j], cur[j-1]) + grid[i][j];
        }

        return cur[n-1];
    }
};
