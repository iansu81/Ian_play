#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
          
        vector<vector<int>> ans;
        // 當interval是空的時候,直接把newInterval放進去vector裡面, 然後return
        if (intervals.size() == 0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        // 原本的interval 已經是sorted,把新的先插進到對的地方
        vector<vector<int>>::iterator it = intervals.begin();
        while (it != intervals.end() && newInterval[0] > (*it)[0])
        {
            it++;
        }
        intervals.insert(it, newInterval);

        // 建立一個空的result, 當result最後一個vector的第二個元素>for loop正在比較vector的第一個元素
        // 代表這兩個vector 要合併ex: [1,3] [2, 6], 3> 2所以要合併
        // 因為已經sort過了,所以取result最後一個vector的第一個元素當新的vector 的第一個元素,
        // 再比較 result最後一個vector的第二個元素跟loop正在比較的vector的第二個元素, 哪個大就取哪個
        for (const auto &element : intervals)
        {
            if (ans.empty() || ans.back()[1] < element[0])
            {
                ans.push_back(element);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], element[1]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> test1 {1, 3};
    vector<int> test2 {6, 9};
    vector<int> new_test {2,5};
    vector< vector<int> > test;
    test.push_back(test1);
    test.push_back(test2);

    Solution sol;
    sol.insert(test, new_test);
}