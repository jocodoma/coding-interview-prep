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
    bool isSymmetric(TreeNode* root) {
        // return isSymmetric_Recursive(root);
        return isSymmetric_Iterative(root);
    }

    bool isSymmetric_Recursive(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (!leftSubtree && !rightSubtree)
            return true;

        if (!leftSubtree || !rightSubtree)
            return false;

        if (leftSubtree->val != rightSubtree->val)
            return false;

        return isMirror(leftSubtree->left, rightSubtree->right)
            && isMirror(leftSubtree->right, rightSubtree->left);
    }

    bool isSymmetric_Iterative(TreeNode* root) {
        if (!root)
            return true;

        std::stack<TreeNode*> stk;
        stk.push(root->right);
        stk.push(root->left);

        while (!stk.empty()) {
            TreeNode *leftNode = stk.top();stk.pop();
            TreeNode *rightNode = stk.top();stk.pop();

            if (!leftNode && !rightNode)
                continue;

            if (!leftNode || !rightNode)
                return false;

            if (leftNode->val != rightNode->val)
                return false;

            stk.push(leftNode->left);
            stk.push(rightNode->right);
            stk.push(leftNode->right);
            stk.push(rightNode->left);
        }

        return true;
    }
};
