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
        // return recursive(root);
        return iterative(root);
    }

private:
    // time complexity: O(n)
    // space complexity: in average O(logn), but worst case is O(n)
    std::vector<int> recursive(TreeNode* root){
        std::vector<int> nodes;
        dfsInorder(root, nodes);
        return nodes;
    }

    void dfsInorder(TreeNode* root, std::vector<int>& nodes){
        if(!root) return;

        dfsInorder(root->left, nodes);
        nodes.push_back(root->val);
        dfsInorder(root->right, nodes);
    }

    // time complexity: O(n), space complexity: O(n)
    std::vector<int> iterative(TreeNode* root){
        std::vector<int> nodes;
        std::stack<TreeNode*> nodeStack;
        while(root || !nodeStack.empty()){
            while(root){
                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top(); nodeStack.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
};
