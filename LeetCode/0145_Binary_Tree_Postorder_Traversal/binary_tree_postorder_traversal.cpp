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
    vector<int> postorderTraversal(TreeNode* root) {
        // return recursiveTraversal(root);
        return iterativeTraversal(root);
    }

    // time complexity: O(n)
    // space complexity: in average is O(log n), but the worst case is O(n)
    vector<int> recursiveTraversal(TreeNode* root){
        recursiveHelper(root);
        return sol;
    }

    void recursiveHelper(TreeNode* node){
        if(!node) return;
        recursiveHelper(node->left);
        recursiveHelper(node->right);
        sol.push_back(node->val);
    }

    // time complexity: O(2n) = O(n), space complexity: O(2n) = O(n)
    vector<int> iterativeTraversal(TreeNode* root){
        if(!root) return {};

        std::stack<TreeNode*> s1, s2;
        s1.push(root);

        while(!s1.empty()){
            TreeNode *node = s1.top();s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }

        while(!s2.empty()){
            TreeNode *node = s2.top();s2.pop();
            sol.push_back(node->val);
        }

        return sol;
    }

private:
    vector<int> sol;
};
