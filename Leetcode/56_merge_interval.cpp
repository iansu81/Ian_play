#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {   

        // sol 1:
        // 暴力法:
        //  直接一個一個比較, 兩個for loop, O(N^2) 

        // sol 2:
        // 先sort O(NlogN)
        // 在for loop sort 好的vector
        // 建立一個空的result, 當result最後一個vector的第二個元素>for loop正在比較vector的第一個元素
        // 代表這兩個vector 要合併ex: [1,3] [2, 6], 3> 2所以要合併
        // 因為已經sort過了,所以取result最後一個vector的第一個元素當新的vector 的第一個元素,
        // 再比較 result最後一個vector的第二個元素跟loop正在比較的vector的第二個元素, 哪個大就取哪個
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
        {
            return a[0] < b[0];
        });

        vector< vector<int >> result;
        
        for(int i = 0; i < intervals.size(); i++)
        {
            if( result.empty() || intervals[i][0] > result.back()[1])
            {
                result.push_back(intervals[i]);
            }
            else
            {   
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }

        }
        
        return result;
        
    }
};

int main()
{

    vector< vector<int> > test {{ 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
    Solution sol;
    vector<vector<int>> result = sol.merge( test);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }
}