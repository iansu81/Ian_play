// 思路:建立一個DP table去紀錄最長的substring
// dp[i][j]代表是在text1的第i個char跟text2的第j個char,common subsequence的長度
// 注意: substring的順序是有關係的, ace 跟cae的結果會完全不一樣
// dp[0][j]跟dp[i][0]都是0
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 1; i <= n1; i ++ ) {
            for(int j = 1; j <= n2; j++) {
                // 找之前最大的value的時候只要比較上面跟左邊的就好了, 左上方的一定<=上面或左邊的
                int max_val = max(dp[i-1][j], dp[i][j-1]);

                // 如果找到相同的char,應該要用左上角的dp值+1,不能用左邊或上面的最大值+1,
                // 因為+1代表兩個string都有這個char,而且已經被訪問過了, 如果用左邊或上面就代表一個有一個沒有
                dp[i][j] = (text1[i-1] == text2[j-1]) ? dp[i-1][j-1]+1 : max_val;
            }
        }
         return dp[n1][n2];
    }
};