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
        return recursivePreOrderTraversal(root, LONG_MIN, LONG_MAX);
        // return recursivePostOrderTraversal(root, LONG_MIN, LONG_MAX);
        // return recursiveInOrderTraversal(root, NULL);
        // return iterativeInOrderTraversal(root);
    }

    // DFS recursive (Pre-order traversal / top-down method)
    // Use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX]
    // potentially have stack overflow
    bool recursivePreOrderTraversal(TreeNode* node, long lower, long upper){
        if(node == NULL)
            return true;
        
        if(node->val <= lower || node->val >= upper)
            return false;
        
        return recursivePreOrderTraversal(node->left, lower, node->val) &&
               recursivePreOrderTraversal(node->right, node->val, upper);
    }

    // DFS recursive (Post-order traversal / bottom-up method)
    // potentially have stack overflow
    bool recursivePostOrderTraversal(TreeNode* node, long lower, long upper){
        if(node == NULL)
            return true;
        
        bool left = recursivePostOrderTraversal(node->left, lower, node->val);
        bool right = recursivePostOrderTraversal(node->right, node->val, upper);

        if(node->val <= lower || node->val >= upper)
            return false;
        
        return left && right;
    }

    // DFS recursive (In-order traversal)
    // potentially have stack overflow
    bool recursiveInOrderTraversal(TreeNode* node, TreeNode*& prev){
        if(!node)
            return true;

        if(!recursiveInOrderTraversal(node->left, prev))
            return false;

        if(prev != NULL && node->val <= prev->val)
            return false;

        prev = node;

        return recursiveInOrderTraversal(node->right, prev);
    }

    // DFS iterative (In-order traversal)
    bool iterativeInOrderTraversal(TreeNode* node){
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
