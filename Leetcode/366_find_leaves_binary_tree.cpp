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
public:
    int getHeight(TreeNode* root, vector<vector<int>>& result) {
        // 在一棵樹裡面, leaves 是第0層, 所以leaves 的下一層也就是nullptr就是第-1層,
        // 同一層的leaves要放在同一個vector裡面
        if(root == nullptr) return -1;

        // 計算左邊的子tree高度跟右邊的子tree高度, 取一個最高的+1(代表更上面一層), 
        int left_height = getHeight(root->left, result);
        int right_height = getHeight(root->right, result);
        int curr_height = max(left_height, right_height) + 1;

        // 當自己目前的height所需要的vector在result vector裡面還不存在的時候, 必須要先push一個空的進去
        if(curr_height == result.size()) result.push_back(vector<int>());

        // 將自己目前的值push進去相對應的height的vector
        result[curr_height].push_back(root->val);

        return curr_height;

    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        getHeight(root, ans);
        return ans;
    }

};


int main() {



}