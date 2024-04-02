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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        TreeNode* tmp = root;
        if(tmp == nullptr) return result;
        queue< TreeNode*> q;
        q.push(tmp);

        // 每一個while iteration 會去遍歷一整層的node
        while(!q.empty()) {
            int n_node = q.size();
            vector<int> row_data(n_node,0);

            for(int i = 0; i < n_node;i++) {
                auto n = q.front();
                q.pop();
                row_data[i] = n->val;
                if(n->left != nullptr) q.push(n->left);
                if(n->right != nullptr) q.push(n->right);

            }
            result.push_back(row_data);
            
        }

        return result;
        
    }
};