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
    int maxDepth(TreeNode* root) {
        // return maxDepth_recursion(root);
        return maxDepth_iteration(root);
    }

    int maxDepth_recursion(TreeNode* root){
        if(!root) return 0;
        return 1 + std::max(maxDepth_recursion(root->left), maxDepth_recursion(root->right));
    }

    int maxDepth_iteration(TreeNode* root){
        if(!root) return 0;

        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int depthLevel = 0;

        while(!nodeQueue.empty()){
            depthLevel++;
            for(int i = 0, s = nodeQueue.size(); i < s; i++){
                TreeNode *currentNode = nodeQueue.front(); nodeQueue.pop();
                if(currentNode->left) nodeQueue.push(currentNode->left);
                if(currentNode->right) nodeQueue.push(currentNode->right);
            }
        }
        return depthLevel;
    }
};
