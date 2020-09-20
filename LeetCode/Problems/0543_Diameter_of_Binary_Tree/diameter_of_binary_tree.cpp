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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        traverseDepth(root, diameter);
        return diameter;
    }

    // time complexity: O(n), space complexity: O(n)
    int traverseDepth(TreeNode* root, int& diameter){
        if(!root) return 0;

        int numLeftPath = traverseDepth(root->left, diameter);
        int numRightPath = traverseDepth(root->right, diameter);
        diameter = std::max(diameter, (numLeftPath + numRightPath));

        return 1 + std::max(numLeftPath, numRightPath);
    }
};
