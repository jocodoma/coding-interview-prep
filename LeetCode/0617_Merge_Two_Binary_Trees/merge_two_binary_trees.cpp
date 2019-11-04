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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // return recursion(t1, t2);
        // return recursionNewTree1(t1, t2);
        // return recursionNewTree2(t1, t2);
        // return iterationDFS(t1, t2);
        return iterationBFS(t1, t2);
    }

    // time complexity: O(m), where m is the number of overlapping nodes between two trees
    // space complexity: O(m)
    // Note: this method does not create new nodes. Instead, it reuses t1 and t2. 
    TreeNode* recursion(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return NULL;
        if(!t1) return t2;
        if(!t2) return t1;

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }

    // time complexity: O(m), space complexity: O(m)
    // create new nodes for overlapping nodes
    // the NOT null nodes will be used as the node of new tree
    TreeNode* recursionNewTree1(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return NULL;
        if(!t1) return t2;
        if(!t2) return t1;

        TreeNode *newNode = new TreeNode(t1->val + t2->val);
        newNode->left = mergeTrees(t1->left, t2->left);
        newNode->right = mergeTrees(t1->right, t2->right);

        return newNode;
    }

    // time complexity: O(n), space complexity: O(n)
    // create a complete new merge tree
    TreeNode* recursionNewTree2(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return NULL;

        TreeNode *newNode = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        newNode->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        newNode->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);

        return newNode;
    }

    TreeNode* iterationDFS(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return NULL;
        if(!t1) return t2;
        if(!t2) return t1;

        std::stack<TreeNode*> s1, s2;
        s1.push(t1);
        s2.push(t2);

        while(!s1.empty()){
            TreeNode *node1 = s1.top(); s1.pop();
            TreeNode *node2 = s2.top(); s2.pop();

            node1->val += node2->val;

            if(!node1->left){
                node1->left = node2->left;
            }
            else if(node1->left && node2->left){
                s1.push(node1->left);
                s2.push(node2->left);
            }

            if(!node1->right){
                node1->right = node2->right;
            }
            else if(node1->right && node2->right){
                s1.push(node1->right);
                s2.push(node2->right);
            }
        }

        return t1;
    }

    TreeNode* iterationBFS(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2) return NULL;
        if(!t1) return t2;
        if(!t2) return t1;

        std::queue<TreeNode*> q1, q2;
        q1.push(t1);
        q2.push(t2);

        while(!q1.empty()){
            TreeNode *node1 = q1.front(); q1.pop();
            TreeNode *node2 = q2.front(); q2.pop();

            node1->val += node2->val;

            if(!node1->left){
                node1->left = node2->left;
            }
            else if(node1->left && node2->left){
                q1.push(node1->left);
                q2.push(node2->left);
            }

            if(!node1->right){
                node1->right = node2->right;
            }
            else if(node1->right && node2->right){
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }

        return t1;
    }
};
