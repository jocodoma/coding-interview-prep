/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Reference:
// https://leetcode.com/problems/path-sum-iii/discuss/141424/Python-step-by-step-walk-through.-Easy-to-understand.-Two-solutions-comparison.-%3A-)

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        // return bruteForce(root, sum);
        return hashTable(root, sum);  // memorization using hash table
    }

    // worst case (single sided tree): time complexity: O(n^2), space complexity: O(n)
    // best case (balanced tree): time complexity: O(nlogn), space complexity: O(logn)

    // traverse every single node in a tree
    int bruteForce(TreeNode* root, int sum){
        if(!root) return 0;
        return rootSum(root, sum) +  bruteForce(root->left, sum) + bruteForce(root->right, sum);
    }

    // find out the number of paths that sum to a given value
    int rootSum(TreeNode* root, int sum){
        if(!root) return 0;

        int count = 0, newSum = 0;
        if(root->val == sum) count++;
        newSum = sum - (root->val);
        count += rootSum(root->left, newSum);
        count += rootSum(root->right, newSum);
        return count;

        // it is same as below
        // return (root->val == sum ? 1 : 0) + rootSum(root->left, sum -(root->val)) + rootSum(root->right, sum -(root->val));
    }

    // time complexity: O(n), space complexity: O(n)
    int hashTable(TreeNode* root, int sum){
        std::unordered_map<int, int> map;  // key: current path sum, value: frequency
        map[0] = 1;  // Initialize with frequency 1 so that we find paths which go all the way from the root
        return traverseDFS(root, sum, map, 0);
    }

    int traverseDFS(TreeNode* root, int sum, std::unordered_map<int, int>& map, int currPathSum){
        if(!root) return 0;
        int count = 0;

        // ->
        currPathSum += root->val;
        count += map[(currPathSum-sum)];
        map[currPathSum]++;
        // <-

        // -> the above code can be explained as below
        // currPathSum = currPathSum + root->val;  // current path sum so far
        // if(map.count(currPathSum-sum))
        //     count = count + map[currPathSum-sum];
        // if(map.count(currPathSum))
        //     map[currPathSum] = map[currPathSum] + 1;
        // else
        //     map[currPathSum] = 1;
        // <-

        count += traverseDFS(root->left, sum, map, currPathSum);
        count += traverseDFS(root->right, sum, map, currPathSum);

        map[currPathSum]--;  // when move to a different branch, the currPathSum is no longer needed

        return count;
    }
};
