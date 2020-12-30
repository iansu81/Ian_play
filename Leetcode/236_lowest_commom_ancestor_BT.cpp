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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // 1.當尋訪到NULL的時候, 代表沒找到, 所以就return NULL
        // 2.當尋訪到p或者是q的時候, 就return p或q
        if( !root || root == p || root == q)
        {
            return root;
        }
        // 接下來對左邊的子tree跟右邊的子tree去做尋訪
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        // 當左邊跟右邊都不是return NULL的時候, 這時候他們共同的root即為答案
        // 當左邊/右邊只有一邊是NULL,代表p＆q,都在另外一側
        // 題目假定p&q必定存在, 所以不考慮找不到的情況 
        if( l && r) return root;
        else if( !l && r) return r;
        else return l;
    }
};