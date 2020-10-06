#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;
// 這邊比84題多做的就是把每一行都視為一個新的histogram 問題, 一開始遍歷所有的'1', 第一行自己分開做,如果自己本身是'1',
// 就用自己正上方的位置數字 ＋ 1（長條圖延伸1）,否則就是0
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if(matrix.size() == 0 ) return 0;
        vector<vector<int>> grid (matrix.size(), vector<int> (matrix[0].size(), 0) );
        build_histogram(matrix, grid);
        int max_area = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            max_area = max(max_area, largestRectangleArea(grid[i]));
        }
        return max_area;
    }
    void build_histogram(vector<vector<char>> &matrix, vector<vector<int>> &grid)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            grid[0][j] = (matrix[0][j] == '1') ? 1 : 0;
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                grid[i][j] = (matrix[i][j] == '1') ? grid[i - 1][j] + 1 : 0;
            }
        }
    }
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i])
            {
                int last_max_height = heights[stk.top()];
                stk.pop();

                max_area = max(max_area, last_max_height * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        while (stk.top() != -1)
        {
            int last_max_height = heights[stk.top()];
            stk.pop();
            max_area = max(max_area, int(last_max_height * (heights.size() - stk.top() - 1)));
        }
        return max_area;
    }
};


int main()
{

    vector<vector<char>> test { { '1', '0', '1', '0', '0' },
                                { '1', '0', '1', '1', '1' }, 
                                { '1', '1', '1', '1', '1' },
                                { '1', '0', '0', '1', '0' } };
    Solution sol;
    cout << "Ans: " << sol.maximalRectangle(test) << endl;

}