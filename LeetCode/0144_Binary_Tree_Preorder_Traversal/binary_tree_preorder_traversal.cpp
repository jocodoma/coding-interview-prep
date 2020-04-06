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
    std::vector<int> preorderTraversal(TreeNode* root) {
        // return recursiveTraversal(root);
        return iterativeTraversal(root);
    }

    std::vector<int> recursiveTraversal(TreeNode* root){
        if(!root)
            return {};
        recursiveHelper(root);
        return sol;
    }

    void recursiveHelper(TreeNode* node){
        sol.push_back(node->val);
        if(node->left)
            recursiveHelper(node->left);
        if(node->right)
            recursiveHelper(node->right);
    }

    std::vector<int> iterativeTraversal(TreeNode* root){
        if(!root)
            return {};

        std::stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode *node = stk.top();stk.pop();
            sol.push_back(node->val);
            if(node->right)
                stk.push(node->right);
            if(node->left)
                stk.push(node->left);
        }

        return sol;
    }

private:
    std::vector<int> sol;
};
