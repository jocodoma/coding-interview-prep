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
    bool isSymmetric(TreeNode* root) {
        // return isSymmetric_Recursive(root);
        return isSymmetric_Iterative(root);
    }

    bool isSymmetric_Recursive(TreeNode* root){
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* leftSubTree, TreeNode* rightSubTree){
        if(!leftSubTree && !rightSubTree) return true;
        if(!leftSubTree || !rightSubTree) return false;
        if(leftSubTree->val != rightSubTree->val) return false;
        return isMirror(leftSubTree->left, rightSubTree->right) && isMirror(leftSubTree->right, rightSubTree->left);
    }

    bool isSymmetric_Iterative(TreeNode* root){
        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        nodeStack.push(root);

        while(!nodeStack.empty()){
            TreeNode *leftNode = nodeStack.top(); nodeStack.pop();
            TreeNode *rightNode = nodeStack.top(); nodeStack.pop();
            if(!leftNode && !rightNode) continue;
            if(!leftNode || !rightNode) return false;
            if(leftNode->val != rightNode->val) return false;
            nodeStack.push(leftNode->left);
            nodeStack.push(rightNode->right);
            nodeStack.push(leftNode->right);
            nodeStack.push(rightNode->left);
        }
        return true;
    }
};
