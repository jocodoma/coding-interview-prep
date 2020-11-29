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
    // time complexity: O(n)
    // space complexity: O(h), where h is the height of the tree. O(n) if tree is unbalanced.
    bool isValidBST(TreeNode* root) {
        return recursivePreOrderTraversal(root, LONG_MIN, LONG_MAX);
        // return recursivePostOrderTraversal(root, LONG_MIN, LONG_MAX);
        // TreeNode *prev = nullptr;
        // return recursiveInOrderTraversal(root, prev);
        // return iterativeInOrderTraversal(root);
    }

    // DFS recursive (Pre-order traversal / top-down method)
    // Use LONG_MIN and LONG_MAX to handle edge cases like [INT_MAX]
    // potentially have stack overflow due to recursive call
    bool recursivePreOrderTraversal(TreeNode* node, long lower, long upper){
        if(node == nullptr)
            return true;

        // BST: lower < node->val < upper
        // -> lower < node->val
        // -> node->val < upper
        if(node->val <= lower || node->val >= upper)
            return false;

        return recursivePreOrderTraversal(node->left, lower, node->val)
            && recursivePreOrderTraversal(node->right, node->val, upper);
    }

    // DFS recursive (Post-order traversal / bottom-up method)
    // potentially have stack overflow due to recursive call
    bool recursivePostOrderTraversal(TreeNode* node, long lower, long upper){
        if(!node)
            return true;

        bool left = recursivePostOrderTraversal(node->left, lower, node->val);
        bool right = recursivePostOrderTraversal(node->right, node->val, upper);

        if(node->val <= lower || node->val >= upper)
            return false;

        return left && right;
    }

    // DFS recursive (In-order traversal)
    // potentially have stack overflow due to recursive call
    bool recursiveInOrderTraversal(TreeNode* node, TreeNode*& prev){
        if(!node)
            return true;

        if(!recursiveInOrderTraversal(node->left, prev))
            return false;

        if(prev && node->val <= prev->val)
            return false;

        prev = node;

        return recursiveInOrderTraversal(node->right, prev);
    }

    // DFS iterative (In-order traversal)
    bool iterativeInOrderTraversal(TreeNode* node){
        std::stack<TreeNode*> stk;
        long preVal = LONG_MIN;

        while(node || !stk.empty()){
            while(node){
                stk.push(node);
                node = node->left;
            }

            node = stk.top();stk.pop();
            if(node->val <= preVal)
                return false;

            preVal = node->val;
            node = node->right;
        }

        return true;
    }
};
