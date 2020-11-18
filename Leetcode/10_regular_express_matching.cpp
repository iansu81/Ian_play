
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        // 建立一個二維vector, 紀錄左邊拿了i個元素, 右邊拿了j個元素之後, 是不是match
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // dp[0][0]代表左邊不拿, 右邊不拿, 兩邊都是空集合, 所以match
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // case 1: 當遍歷到'*'的時候比較麻煩, 會有兩種情況：
                // a) 當星號前面的元素, 重複0次的時候, 這時候答案就是dp[i][j] == dp[i][j-2] , P取j個跟取j-2個答案一樣, 因為星號跟它前面的元素都可以不要
                // b) 當星號前面的元素, 重複至少一次的時候, 這時後要確定 dp[i-1][j]也就是s拿i-1個的時候已經是match了
                //    在加上現在遍歷的s中的元素s[i-1]跟'*'前面的元素,也就是p[j-2]是相等的,或者p[j-2] = '.'

                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] ||
                               (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }  
                // case 2:  dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                // ex: (abc, abc) & (abc, a..)  當比較的對象沒有'*'的時候, 只要看到s取i-1個跟p取j-1個的解跟字母i,j是不是相符合或者是是不是'.',
                // 在這邊要確認s[i-1]跟p[j-1]是因為在dp[i][j]裡面i,j代表的是元素數量, s[i-1], p[j-1]的i-1,j-1代表index
                else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};