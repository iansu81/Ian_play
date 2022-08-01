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
class BSTIterator {
    // 利用一個stack來存root跟左子tree的元素
    // 為何只要存左子tree? 因為如果是inorder traversal , 只要把左子tree存下來, 做inorder就也可以尋訪到右子tree
private:
    stack<TreeNode*> record;
public:

    void push_node(TreeNode* root) {
        TreeNode* temp = root;
        while(temp != nullptr) {
            record.push(temp);
            temp = temp->left;
        }
        
    }
    // 將root跟
    BSTIterator(TreeNode* root) {
       push_node(root);
    }
    // Inorder traversal: pop一個元素之後, 確認它有沒有右子tree, 有的話, 再把這個右子tree裡面所有左邊的元素push進去
    int next() {
        TreeNode* node = record.top();
        record.pop();
        if(node->right != nullptr) push_node(node->right);
        return node->val; 
        
    }
    
    bool hasNext() {
        return !record.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */