class Solution {
private:
    vector<vector<int>> dp;
    int n_row;
    int n_col;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        n_row = matrix.size();
        n_col = matrix[0].size();

        // 利用一個dp matrix來記錄之前走過的路
        dp = vector<vector<int>>(n_row, vector<int>(n_col, -1));
        int ans = 0;
        for(int i = 0; i < n_row; i++){
            for(int j = 0 ; j < matrix[i].size(); j++){
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int row_idx, int col_idx){

        // 當dp 已經尋訪過了, 就不用再走一遍了
        if(dp[row_idx][col_idx] != -1) return dp[row_idx][col_idx];
        
        //還沒走過的話先設成1 
        dp[row_idx][col_idx] = 1;

        // 走上下左右
        vector<int> movement{-1,0,1,0,-1};
        for(int i = 0; i < 4; i ++) {
            int new_row_idx = row_idx + movement[i];
            int new_col_idx = col_idx + movement[i+1];
            if(new_row_idx < 0 || new_row_idx >= n_row || new_col_idx < 0 || new_col_idx >= n_col || 
            matrix[new_row_idx][new_col_idx] <= matrix[row_idx][col_idx])
            continue;

            // 目前的dp會是上下左右最大的+1, 上下左右block裡面可以走最常路徑的+1步
            dp[row_idx][col_idx] = max(dp[row_idx][col_idx], 1+dfs(matrix, new_row_idx, new_col_idx));
        }
        return dp[row_idx][col_idx];


    }
};