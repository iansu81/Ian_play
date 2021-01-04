#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;

// key idea: dynamic programming. DP[0] = 0 因為 0 元最少用0個硬幣就可以組合出來
// INT_MAX代表解不出來
//dp[ammount] = 可以組成這個amount最少的硬幣數量
//從amount = 0 開始往上做, 這可以讓我們保證在這vector dp中每個amount都是最少的硬幣數量
//接著做下一個amount的時候,interate coin的數值每次都減掉這個數值再加一比看看哪一個最小, 這樣就能找到在這些硬幣的組合下最小數量的組合(前面的已經是最小的了, 再加上一個最小數量的硬幣也會是最小的)
// ex: coin = [1,2,5] => dp[0] = 0, dp[1] = 1(一個1塊) dp[2] = min(dp[1] + 1(兩個一塊)(dp[2-1]), dp[0]+1（一個兩塊）(dp[2-2]).....)


class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++)
        {
            for(const auto& c: coins)
            {
                // 這邊要多比較一個dp[i-c] != INT_MAX是因為假設coins只有2, amout 是3
                // 這種情況下是沒有解的, 這時候dp[i-c]就會是INT_MAX, INT_MAX+1會爆掉
    
                if( (i - c) >= 0 && dp[i-c] != INT_MAX )
                {
                    dp[i] = min(dp[i], dp[i-c] + 1);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};


int main()
{
    // vector<int> test{186, 419, 83, 408};
    
    // Solution sol;
    // cout << "Ans: " << sol.coinChange(test, 6249);

    vector<int> test{1, 2, 5};
    Solution sol;
    cout << "Ans: " << sol.coinChange(test, 11);
}