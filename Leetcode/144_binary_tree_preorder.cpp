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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        stack<TreeNode*> record;
        record.push(root);

        while(!record.empty()) {
            TreeNode* tmp = record.top();
            record.pop();
            result.push_back(tmp->val);
            if(tmp->right != nullptr) record.push(tmp->right);
            if(tmp->left != nullptr) record.push(tmp->left);
        }

        return result;
    }
};