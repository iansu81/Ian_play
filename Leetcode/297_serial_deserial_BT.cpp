/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 重點: dederialize 的時候建立treenode一定要new,不然離開function就消失了
// 另外不論serialize或deserialize,都是先左再右
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream s(data);
        return helper(s);
    }
    TreeNode *helper(stringstream &data)
    {
        string s;
        data >> s;
        if (s == "#")
            return nullptr;
        TreeNode *root = new TreeNode();
        root->val = stoi(s);
        root->left = helper(data);
        root->right = helper(data);
        return root;
    }
};