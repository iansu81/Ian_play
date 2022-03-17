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
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        // 如果input是空, 直接回傳空vector
        vector<vector<int>> result;
        if(root == nullptr) return result;
        

        // 建立一個queue來做BFS,pair第一個值是node, 第二個值記錄在哪個column, 接著push root到這個queue
        queue<std::pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        // 利用一個hash map來記錄相同的column下的元素, 因為最後寫到vector的時候要知道最小從哪裡開始跑for loop跟最大跑到哪裡，
        // 所以利用兩個最小最大來記錄最後for loop的start & end
        unordered_map<int, vector<int>> record;
        int col_min = 0;
        int col_max = 0;


        // BFS
        while( !q.empty() ) {
            std::pair<TreeNode*, int> tmp = q.front();
            q.pop();
            record[tmp.second].push_back(tmp.first->val);
            col_min = min(col_min, tmp.second);
            col_max = max(col_max, tmp.second);
            // 往左找column-1
            if(tmp.first->left != nullptr) {
                q.push(make_pair(tmp.first->left, tmp.second-1));
                
            }
            // 往右找column+1
            if(tmp.first->right != nullptr) {
                q.push(make_pair(tmp.first->right, tmp.second+1));
            }
        }

        // 將unordered_map裡面所有元素從最小的column到最大的column iterate一遍push到vector裡
        for(int i = col_min; i <= col_max; i++ ) {
            result.push_back(record[i]);
        }

        return result;


    }
};