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

        // BST 特徵, 左邊所有子tree的element一定比右邊所有子tree的element大
        // 如果剛好p跟q在tree的一左一右, 那目前的root就是他們的LCA
        // 如果p跟q都比root小, 那它面兩個必定在左邊的子tree
        // 如果p跟q比root大, 兩個node必定都在右邊的子tree
        if( (root->val > p->val) && (root->val > q->val) ) return lowestCommonAncestor( root->left, p, q);
        if( (root->val < p->val) && (root->val < q->val) ) return lowestCommonAncestor( root->right, p, q);

        return root;
        
    }
};