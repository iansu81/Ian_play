#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

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
class Solution {
private:
    int ans = 0;
public:
    int largestBSTSubtree(TreeNode* root) {
        helper(root);
        return ans;
        
    }

    vector<int> helper(TreeNode* root){
        
        // 利用一個vector來記錄現在這個root底下的subtree的特徵
        // [1.是不是一個binary search tree, 2.subtree裡面node值的最小值, 3. subtree裡面node值的最大值, 4. subtree有幾個node]
        // 如果root是一個nullptr, 代表子tree是一個subtree, 但是沒有任何node.
        if(root == nullptr) return {1, INT_MAX, INT_MIN, 0};
        
        // 取得left 跟right 子tree的特徵
        auto left = helper(root->left);
        auto right = helper(root->right);

        // 如果左邊的子tree跟右邊的子tree都是BST, 再加上root的值大於左邊子tree的最大值, root的值小於右邊子tree的最小值, 
        // 我們就可以判定現在這個root底下是一個BST
        if( left[0] == 1 && right[0] == 1 && (root->val > left[2]) && (root->val < right[1]) ) {

            // 最大的subtree node數量就是左邊的數量+右邊的數量+root
            ans = max(ans, left[3]+right[3]+1);

            // 第二項跟第三項一定要做min, max , 因為在tree的尾巴null_ptr我們initialize成INT_MAX 跟 INT_MIN, 沒有做這件事的話直接用left[1]跟right[2]的話
            // 子subtree的最小值會一直是INT_MAX 跟INT_MIN
            return {1, min(root->val, left[1]), max(root->val, right[2]) ,left[3]+right[3]+1};
        }
        return {0, INT_MAX, INT_MIN, 0};


    }
};