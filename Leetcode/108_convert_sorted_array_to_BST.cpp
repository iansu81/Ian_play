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
    TreeNode* helper(vector<int>& nums, int left, int right) {
        

        // 停止條件, 用5個元素下去跑一遍就可以找到
        if(left > right) return nullptr;

        // 把mid當root開始build, 答案不唯一
        int mid = left+ (right - left)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively 去create子tree
        root->left = helper(nums, left, mid-1);
        root->right = helper(nums, mid+1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};