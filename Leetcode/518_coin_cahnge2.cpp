#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


// solution 1 : 利用一個二維矩陣來紀錄  i:使用了幾個硬幣, 0代表用0個    j: amount
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // amount 跟coin都多加1因為可以取0個硬幣,跟0元
        vector<vector<int>> dp(coins.size()+1, vector<int>( amount+1, 0));
        // 用0個硬幣去換0元有一種方法, 用0跟硬幣去換n元都是0種方法 i.e. dp[0][1.....amount] = 0
        dp[0][0] = 1;

        // dp[i][j]的意義是用前i個硬幣(index 到i-1)去組成j amount的組合
        // 所以會等於d[i-1][j](用前i-1個硬幣)去組成j, 加上sum of d[i][j-k*coins[i-1]]. k = 1,2,3直到index 變成負的
        // (當1,2,....k個coins[i-1]硬幣去組成amount j 時候的情況). 第二個部份又剛好等於d[i][j - coins[i-1]]
        // 展開的部份可以看youtube視頻
        for(int i = 1; i <= coins.size(); i++)
        {
            for(int j = 0; j <= amount ; j++)
            {
                dp[i][j] = dp[i-1][j] + ( (j - coins[i-1]) >= 0 ? dp[i][j - coins[i-1]] : 0);
            }
        }
        return dp[coins.size()][amount];
        
    }
};


// solution 2 :只用一個一維矩陣來紀錄dp, 因為dp[i][j]只在意dp[i-1][j]跟dp[i][j-coins[i-1]]
// 根本不在意dp[i-1,-2,-3][1.....j-1],也就是說它只在意自己的正上方跟同一排之前的,所以其實只要amount＋1的size就好了
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 建立一個amount+1大小ㄉdp就好
        vector<int> dp( amount+1, 0);
        // 一開始代表0個硬幣amount 0, 然後第一排後面都是0不用管它
        dp[0] = 1;
        // 接下來就開始遍歷各個coin
        for(auto coin: coins)
        {
            // 從coin開始是因為coin之前的數字一定跟上面一排一模一樣,就不用管他
            // 然後dp[i]＝ dp[i] + dp[i-coin]
            // 加入新的一種硬幣之後去組成amount i 的組合 == 沒有新硬幣去組成amount i的組合＋新硬幣去組成amount (j- 新硬幣)的組合
            for(int i = coin; i <= amount ; i++)
            {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
        
    }
};

int main()
{
    vector<int> test {10};
    Solution sol;
    cout << "Ans: " << sol.change(10, test) << endl;
}
