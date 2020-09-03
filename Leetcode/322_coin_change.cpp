#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = 0;
        sort(coins.begin(), coins.end(), [](const auto & left, const auto & right) -> bool
        {
            return left > right;
        });
        for(auto e: coins)
        {
            if(amount >= e)
            {
                cout << "amount: " << amount << endl;
                int remainder = amount%e;
                cout << "Remainder: " << remainder << endl;
                cout << "E: " << e << endl;
                ans += amount/e;
                amount = remainder;
            }
        }
        if(amount == 0) return ans;
        else return -1;
    }
};


int main()
{
    vector<int> test{186, 419, 83, 408};
    Solution sol;
    cout << "Ans: " << sol.coinChange(test, 6249);
}
