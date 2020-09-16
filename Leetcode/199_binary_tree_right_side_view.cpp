#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
// 從Tree 的最上面開始找做dfs, 然後每次先找右邊的node, 因為是從右邊看, 如果有右邊的node就一定是我們要找的數, 所以每次dfs下一層 當level = result.size()的時候
// ex: level = 0 , result = 0, 這時候目前尋訪的這元素就是這一層最右邊的元素也是我們想要的元素. 右邊的尋訪完了再尋訪左邊


class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        dfs(root, 0 , result);
        return result;
    }
    void dfs(TreeNode *root, int level, vector<int> &result)
    {
        if( root == nullptr)
        {
            return;
        }
        if(level == result.size())
        {
            result.push_back(root->val);
        }
        dfs(root->right, level + 1, result);
        dfs(root->left, level + 1, result);
    }
};