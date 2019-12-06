class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination1(m, n);
        // return combination2(m, n);
        // return dpArray(m, n);
        // return dpVector(m, n);
        // return dp2(m, n);
        // return dp3(m, n);
    }

    // Reference: https://betterexplained.com/articles/navigate-a-grid-using-combinations-and-permutations/

    // time complexity: O(min(m,n)), space complexity: O(1)
    int combination1(int m, int n){
        if(m < 1 || n < 1) return 0;

        int N = m + n - 2;  // (m-1) down and (n-1) right, hence the total is (m-1)+(n-1)
        int maxK = std::max(m - 1, n - 1);
        int minK = std::min(m - 1, n - 1);
        long int numerator = 1, denominator = 1;

        for(int i = N; i > maxK; i--) numerator *= i;
        for(int i = 2; i <= minK; i++) denominator *= i;

        return (numerator / denominator);
    }

    // time complexity: O(min(m,n)), space complexity: O(1)
    int combination2(int m, int n){
        if(m < 1 || n < 1) return 0;

        int maxK = std::max(m - 1, n - 1);
        int minK = std::min(m - 1, n - 1);
        long int numerator = 1, denominator = 1;

        for(int i = 1; i <= minK; i++){
            numerator *= (maxK + i);
            denominator *= i;
        }
        return (numerator / denominator);
    }

    // time complexity: O(mn), space complexity: O(mn)
    int dpArray(int m, int n){
        if(m < 1 || n < 1) return 0;

        // initialization
        int dp[m][n] = {};  // for c => int dp[m][n] = {0};
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
    }

    // time complexity: O(mn), space complexity: O(mn)
    int dpVector(int m, int n){
        if(m < 1 || n < 1) return 0;

        // create a vector containing m vectors of size n with value 1
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
    }

    // Reference: https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    // The above solution runs in O(mn) time and costs O(mn) space.
    // However, you may have noticed that each time when we update dp[i][j],
    // we only need dp[i - 1][j] (at the previous row) and dp[i][j - 1] (at the current row).
    // So we can reduce the memory usage to just two rows (O(n)).

    // time complexity: O(mn), space complexity: O(2n) = O(n)
    int dp2(int m, int n){
        if(m < 1 || n < 1) return 0;

        std::vector<int> pre(n, 1), cur(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                cur[j] = pre[j] + cur[j-1];

            std::swap(pre, cur);
        }

        return pre[n-1];
    }

    // Reference: https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
    // Further inspecting the above code, pre[j] is just the cur[j] before the update.
    // So we can further reduce the memory usage to one row.

    // time complexity: O(mn), space complexity: O(n)
    int dp3(int m, int n){
        if(m < 1 || n < 1) return 0;

        std::vector<int> cur(n, 1);
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                cur[j] += cur[j-1];

        return cur[n-1];
    }
};
