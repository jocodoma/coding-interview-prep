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
    // time complexity: O(n)
    // space complexity: O(n) if the tree is unbalanced, O(log n) if tree is balanced
    bool isValidBST(TreeNode* root) {
        return recursiveTopDownHelper(root, LONG_MIN, LONG_MAX);
        // return recursiveBottomUpHelper(root, LONG_MIN, LONG_MAX);
        // return recursiveInOrderTraversal(root);
        // return iterativeInOrderTraversalHelper(root);
    }

    // DFS recursive (top-down method)
    // Use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX]
    // potentially have stack overflow
    bool recursiveTopDownHelper(TreeNode* node, long lower, long upper){
        if(node == NULL)
            return true;
        
        if(node->val <= lower || node->val >= upper)
            return false;
        
        return recursiveTopDownHelper(node->left, lower, node->val) &&
               recursiveTopDownHelper(node->right, node->val, upper);
    }

    // DFS recursive (bottom-up method)
    // potentially have stack overflow
    bool recursiveBottomUpHelper(TreeNode* node, long lower, long upper){
        if(node == NULL)
            return true;
        
        bool left = recursiveBottomUpHelper(node->left, lower, node->val);
        bool right = recursiveBottomUpHelper(node->right, node->val, upper);

        if(node->val <= lower || node->val >= upper)
            return false;
        
        return left && right;
    }

    // DFS recursive (inorder traversal)
    // potentially have stack overflow
    bool recursiveInOrderTraversal(TreeNode* node){
        TreeNode *prev = NULL;
        return recursiveInOrderTraversalHelper(node, prev);
    }

    bool recursiveInOrderTraversalHelper(TreeNode* node, TreeNode*& prev){
        if(!node)
            return true;

        if(!recursiveInOrderTraversalHelper(node->left, prev))
            return false;

        if(prev != NULL && node->val <= prev->val)
            return false;

        prev = node;

        return recursiveInOrderTraversalHelper(node->right, prev);
    }

    // DFS iterative (inorder traversal + bottom up)
    bool iterativeInOrderTraversalHelper(TreeNode* node){
        std::stack<TreeNode*> todoStk;
        long preVal = LONG_MIN;

        while(node || !todoStk.empty()){
            while(node){
                todoStk.push(node);
                node = node->left;
            }

            node = todoStk.top(); todoStk.pop();
            if(node->val <= preVal)
                return false;

            preVal = node->val;
            node = node->right;
        }

        return true;
    }
};
