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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 一定要先確定root是不是nullptr, 如果一開始root是nullptr就會報錯
        if(root) {

            // 如果key比root小, 往左邊子tree找
            if(key < (root->val) ) root->left = deleteNode(root->left, key);
            // 如果key比root大, 往右邊子tree找
            else if(key > (root->val)) root->right = deleteNode(root->right, key);
            // 找到跟key一樣大的node
            else{

                // 當node是一個leaf時, 直接刪掉即可
                if((root->left == nullptr) && (root->right == nullptr)) return nullptr;

                // 當node有一個子node的情況, 就把node替換成子node
                else if( (root->left==nullptr) || (root->right==nullptr) )
                    return (root->left!=nullptr ? root->left : root->right);

                // 當node有兩個子node的情況, 有兩種選擇:
                // 1. 拿左子tree最大的值來替換掉node, 
                // 2. 或是拿右子tree最小的值替換掉node
                // 作法1
                // 先走到左邊子tree的root
                TreeNode* tmp = root->left;

                // 如果有右邊的子tree一直往右邊找(才能找到左邊子tree最大的)
                while(tmp->right != nullptr) tmp = tmp->right;

                // 接下來把這個左邊子tree最大值assign給root
                root->val = tmp->val;

                // 這一步用來刪除左邊子tree最大值這個node
                root->left = deleteNode(root->left, tmp->val);



                // 做法2
                // TreeNode *temp = root->right;
                // while(temp->left != NULL) temp = temp->left;
                // root->val = temp->val;
                // root->right = deleteNode(root->right, temp);	
            }
        }
        return root;

    }
};



