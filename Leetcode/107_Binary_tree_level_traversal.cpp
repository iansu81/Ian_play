


// DFS 寫法 
void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
    if (!node) return;
    if (level >= ans.size())
        ans.push_back({});
    ans[level].push_back(node->val);
    levelOrder(ans,node->left,level+1);
    levelOrder(ans,node->right,level+1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    levelOrder(ans,root,0);
    reverse(ans.begin(),ans.end());
    return ans;
}


// 另一種寫法

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        TreeNode* tmp = root;
        vector<vector<int>> result;
        if(tmp == nullptr) return result;
        queue<TreeNode*> record;
        record.push(tmp);
        
        while(!record.empty()) {

            int num_node = record.size();
            vector<int> row(num_node,0);
            for(int i = 0; i < num_node; i++){
                TreeNode* node = record.front();
                record.pop();
                row[i] = node->val;
                if(node->left != nullptr) record.push(node->left);
                if(node->right != nullptr) record.push(node->right);
            }
            result.push_back(row);
            
        }
        reverse(result.begin(), result.end());
        return result;
        
        
    }
};