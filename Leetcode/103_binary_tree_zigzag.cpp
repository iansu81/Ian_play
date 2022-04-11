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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;

        while(!q.empty()) {
            
            int num_element = q.size();
            vector<int> row(num_element);
            for(int i = 0 ; i < num_element; i++) {
                int index = left_to_right : i ? (size - 1 - i);
                TreeNode* temp = q.front();
                row[index] = temp->val;
                q.pop_front();
                if(temp->left != nullptr) q.push_back(temp->left);
                if(temp->right != nullptr) q.push_back(temp->right);
            }

            result.push_back(row);
            left_to_right = !left_to_right;

        }
    }
};