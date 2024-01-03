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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stk;
        stk.push(root);
        stack<int> output;
        vector<int> ans;
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            stk.pop();
            output.push(temp->val);
            if(temp->left) stk.push(temp->left);
            if(temp->right) stk.push(temp->right);
        }
        while(!output.empty()){
            ans.push_back(output.top());
            output.pop();
        }
        return ans;
    }
};