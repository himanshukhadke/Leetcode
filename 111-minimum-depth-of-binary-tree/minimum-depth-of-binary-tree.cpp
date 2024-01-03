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

    int dfs(TreeNode* node){
        if(!node) return 100005;
        if(!node->left and !node->right){
            return 1;
        }
        return 1+min(dfs(node->left),dfs(node->right));
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }
};