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

// 利用inorder traversal來找第K個最小的element
// 左邊的子tree一定是比較小的, 所以inorder從左邊找起, 可以從最小的開始找起
// 每碰到一個node, path就加1, 一直找到path == k就是第K個最小的

class Solution {
public:

    void inorder(TreeNode* root, int k, int& path, int& val) {
        if(root == nullptr) return;
        if(path >= k) return;
        inorder(root->left, k, path, val);
        if(++path == k) {

            val = root->val;
            // 這邊一定要加一個return, 如果找到了就不用往右邊找右邊子tree 繼續找
            return;
        }
        inorder(root->right, k, path, val);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int path = 0;
        inorder(root, k, path, ans);
        return ans;
    }
};