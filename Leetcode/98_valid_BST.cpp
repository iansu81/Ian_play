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


// 每個node都會有限制, 在右邊子tree的左node一定要比root小, 但是又不能小於整棵樹的root, 
// 在左邊子tree的右node一定要比root大, 但又不能比整棵樹的root大
// 每次往左邊找, 就update上限, 往右邊找,就update下限, 只要位在上限下限中間, 就是valid

class Solution {
public:
    // 整棵樹的root沒有限制, 但是因為題目的val限制在INT_MIN~INT_MAX, 所以要設成比INT_MIN小跟比INT_MAX大, 設成不可能的值
    bool isValidBST(TreeNode* root) {
        return isValid(root, double(INT_MIN)-1, double(INT_MAX)+1);
    }
    bool isValid(TreeNode* root, double low, double high)
    {
        // 找到nullptr的時候, 代表以下的都符合, return true
        if(root == nullptr) return true;
        if( (low >= INT_MIN && root->val <= low ) || ( high <= INT_MAX && root->val >= high) ) 
        {
            return false;
        }
        
        return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }
};
