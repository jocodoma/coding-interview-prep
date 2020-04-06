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
    vector<int> inorderTraversal(TreeNode* root) {
        // return recursiveTraversal(root);
        return iterativeTraversal(root);
    }

private:
    // time complexity: O(n)
    // space complexity: in average is O(log n), but the worst case is O(n)
    std::vector<int> recursiveTraversal(TreeNode* root){
        recursiveHelper(root);
        return sol;
    }

    void recursiveHelper(TreeNode* node){
        if(!node) return;
        recursiveHelper(node->left);
        sol.push_back(node->val);
        recursiveHelper(node->right);
    }

    // time complexity: O(n), space complexity: O(n)
    std::vector<int> iterativeTraversal(TreeNode* root){
        if(!root) return {};

        std::stack<TreeNode*> stk;
        TreeNode *node = root;

        while(node || !stk.empty()){
            while(node){
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            sol.push_back(node->val);
            node = node->right;
        }
        return sol;
    }

private:
    vector<int> sol;
};
