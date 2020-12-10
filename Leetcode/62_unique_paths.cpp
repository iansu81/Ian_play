#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


// 因為只能向下或者向右走, 所以最左邊的一行, 跟最上面的一列的所有元素, 一定都只有一種走法
// 其他的元素, 都有兩個來源, 一個是自己正上方, 一個是左邊的, 兩者加起來, 走到目前的元素可能的走法
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j< n ; ++j )
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

};

int main()
{
    Solution sol;
    cout << "Ans: " << sol.uniquePaths(7,3) << endl;
}