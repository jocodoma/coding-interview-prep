/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // return checkBalanced1(root);
        return checkBalanced2(root).first;
    }

private:
    // time complexity: O(n)
    // space complexity: O(h), where h is the height of the tree
    bool checkBalanced1(TreeNode* node) {
        if(!node)
            return true;

        int lh = findHeight(node->left);
        int rh = findHeight(node->right);

        return std::abs(lh - rh) <= 1
            && checkBalanced1(node->left)
            && checkBalanced1(node->right);
    }

    int findHeight(TreeNode* node) {
        if(!node)
            return 0;

        // return 1 + std::max(findHeight(node->left), findHeight(node->right));

        // same as above return statement
        int lh = findHeight(node->left);
        int rh = findHeight(node->right);
        return 1 + (lh > rh ? lh : rh);
    }

    // time complexity: O(n)
    // space complexity: O(h), where h is the height of the tree
    std::pair<bool, int> checkBalanced2(TreeNode* node) {
        if (!node)
            return {true, 0};

        auto left = checkBalanced2(node->left);
        if (!left.first)
            return {false, 0};

        auto right = checkBalanced2(node->right);
        if (!right.first)
            return {false, 0};

        bool isBalance = std::abs(left.second - right.second) <= 1;
        int height = 1 + std::max(left.second, right.second);

        return {isBalance, height};
    }
};
