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
    TreeNode* invertTree(TreeNode* root) {
        // return recursion(root);
        // return iteration_stack(root);
        return iteration_queue(root);
    }

    // time complexity: O(n), space complexity: O(h) -> O(n)
    TreeNode* recursion(TreeNode* root){
        if(!root) return NULL;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = recursion(right);
        root->right = recursion(left);
        return root;
    }

    // time complexity: O(n), space complexity: O(h) -> O(n)
    TreeNode* iteration_stack(TreeNode* root){
        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);

        while(!nodeStack.empty()){
            TreeNode *node = nodeStack.top(); nodeStack.pop();
            if(node){
                TreeNode *left = node->left, *right = node->right;
                nodeStack.push(left);
                nodeStack.push(right);
                node->left = right;
                node->right = left;
            }
        }
        return root;
    }

    // time complexity: O(n), space complexity: O(n)
    TreeNode* iteration_queue(TreeNode* root){
        if(!root) return NULL;
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            TreeNode *node = nodeQueue.front(); nodeQueue.pop();
            if(node){
                TreeNode *left = node->left, *right = node->right;
                if(left) nodeQueue.push(left);
                if(right) nodeQueue.push(right);
                node->left = right;
                node->right = left;
            }
        }
        return root;
    }
};
