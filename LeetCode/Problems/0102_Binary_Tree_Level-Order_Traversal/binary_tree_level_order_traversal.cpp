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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // return recursiveTraversal_1(root);
        // return recursiveTraversal_2(root);
        return iterativeTraversal(root);
    }

    // time complexity: O(n)
    // space complexity: in average is O(log n), but the worst case is O(n), or O(height of tree)
    vector<vector<int>> recursiveTraversal_1(TreeNode* root){
        int h = findHeight(root);
        for(int i = 0; i < h; i++){
            vector<int> subSol;
            recursiveHelper_1(root, i, subSol);
            sol.push_back(subSol);
        }
        return sol;
    }

    void recursiveHelper_1(TreeNode* node, int level, vector<int>& subSol){
        if(!node) return;
        if(level == 0){
            subSol.push_back(node->val);
        }
        else{
            recursiveHelper_1(node->left, level-1, subSol);
            recursiveHelper_1(node->right, level-1, subSol);
        }
    }

    int findHeight(TreeNode* node){
        if(!node) return 0;
        int lh = findHeight(node->left);
        int rh = findHeight(node->right);
        return (lh > rh) ? lh + 1 : rh + 1;
    }

    // time complexity: O(n)
    // space complexity: in average is O(log n), but the worst case is O(n), or O(height of tree)
    vector<vector<int>> recursiveTraversal_2(TreeNode* root){
        recursiveHelper_2(root, 0);
        return sol;
    }

    void recursiveHelper_2(TreeNode* node, int depth){
        if(!node) return;
        if(sol.size() == depth) sol.emplace_back(vector<int>());
        sol[depth].emplace_back(node->val);
        recursiveHelper_2(node->left, depth+1);
        recursiveHelper_2(node->right, depth+1);
    }

    vector<vector<int>> iterativeTraversal(TreeNode* root){
        if(!root) return {};

        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> subSol;
            for(int i = 0; i < n; i++){
                TreeNode *node = q.front();q.pop();
                subSol.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sol.push_back(subSol);
        }

        return sol;
    }

private:
    vector<vector<int>> sol;
};
