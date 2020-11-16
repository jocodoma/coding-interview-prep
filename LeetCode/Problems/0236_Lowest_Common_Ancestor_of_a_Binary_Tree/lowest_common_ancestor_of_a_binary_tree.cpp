/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recursion(root, p, q);
        // return recursion_with_pair(root, p, q);
    }

private:
    // time complexity: O(n)
    // space complexity: O(h), where h is the height of the tree
    TreeNode* recursion(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node)
            return nullptr;

        if(node == p || node == q)
            return node;

        TreeNode *left = recursion(node->left, p, q);
        TreeNode *right = recursion(node->right, p, q);

        if(left && right)
            return node;

        return left ? left : right;
    }

    // time complexity: O(n)
    // space complexity: O(h), where h is the height of the tree
    TreeNode* recursion_with_pair(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q).second;
    }

    std::pair<int, TreeNode*> helper(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node)
            return {0, nullptr};

        auto left = helper(node->left, p, q);
        if (left.first == 2)
            return left;

        auto right = helper(node->right, p, q);
        if (right.first == 2)
            return right;

        int numTargetNodes = left.first + right.first + (node == p) + (node == q);

        return {numTargetNodes, numTargetNodes == 2 ? node : nullptr};
    }
};
