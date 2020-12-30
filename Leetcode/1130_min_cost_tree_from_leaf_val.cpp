#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <limits.h>


using namespace std;

// 思路：Greedy, 先儘量找小的去形成上一層的node, 這樣才會最小
// ex: [6,2,4] 2必須先跟4合併成8然後,然後再加上24, 如果6跟2先做, 就不會是最小的

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> record;
        record.push_back(INT_MAX);
        // 利用vector建立一個類似stack的結構, 每當碰到大,小,大的情況,
        // 就把小的數移除掉,跟旁邊兩個比較小的合併, 並維持這個stack單調遞減,
        // 合併移除的時候, 會有一個cost, 這個cost就是小的數跟旁邊兩個數比較小的那個形成的node,
        // 最後我們得到一個單調遞減的stack, 接下來從後面每次取兩個來形成一個node, 把比較小的remove掉, 保留比較大的, 繼續跟第二小, 第三小的去形成node,
        // 最後得到的解就會是最小的  
        for(auto &e: arr)
        {
            while(record.back() <= e)
            {
                int temp = record.back();
                record.pop_back();
                res += temp * min(record.back(), e);
            }
            
            record.push_back(e);
        }
        for(int i = (record.size()-1); i > 1; i--)
        {
            res += record[i]*record[i-1];
        }
        return res;
    }
};


int main()
{
    vector<int> test{6,2,4};
    Solution sol;
    cout << "Ans: " << sol.mctFromLeafValues(test) << endl;



}