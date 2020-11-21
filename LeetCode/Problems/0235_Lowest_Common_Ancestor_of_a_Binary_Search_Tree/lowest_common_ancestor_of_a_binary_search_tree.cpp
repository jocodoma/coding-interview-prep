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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return recursive(root, p, q);
        return iterative(root, p, q);
    }

private:
    TreeNode* recursive(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || !p || !q)
            return root;

        if(p->val > q->val)
            std::swap(p, q);

        return helper(root, p, q);
    }

    TreeNode* helper(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node->val < p->val)
            return helper(node->right, p, q);

        if(node->val > q->val)
            return helper(node->left, p, q);

        return node;
    }

    TreeNode* recursive(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || !p || !q)
            return root;

        if(p->val > q->val)
            std::swap(p, q);

        TreeNode *node = root;

        while(node->val < p->val || node->val > q->val){
            while(node->val < p->val)
                node = node->right;

            while(node->val > q->val)
                node = node->left;
        }

        return node;
    }
};
