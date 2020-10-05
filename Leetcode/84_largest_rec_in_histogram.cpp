#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>


using namespace std;

// 作法：

// 1. 建立一個單調遞增的stack, 用來記錄index, 並且先push 一個-1進去, ex : 當height[i] <= height[stack top] = > 就必須要把stack中的元素拿出來操作 
// 2. pop出來時候的公式 height[stack[top]] * (i−stack[top−1]−1)
//     ex: [2,3,1] index: 0,1,2
//     把2,3 也就是 index = 0 ,index = 1都push到stack中之後, 當i跑到index = 2的時候 height[stack[top]] = height[1] = 3
//     => 3 * (i = 2 - stack[0](index:0) - 1 ) = 3
//     接下來因為2 > 1 所以也要再做一次

// 3. 每次pop之後跟最大的max_area比並且記錄下來

// 4. iterate 完之後,如果stack的top ！＝ -1, 也要把元素一個一個pop出來, 但是公式中的i 被換成 height的元素數量





class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for(int i = 0; i < heights.size(); i++ )
        {
            while(stk.top() != -1  && heights[stk.top()] >= heights[i] )
            {
                int last_max_height = heights[stk.top()];
                stk.pop();
        
                max_area = max(max_area, last_max_height* (i - stk.top() - 1));                                                
            } 
            stk.push(i);
        }
        while(stk.top() != -1)
        {
            int last_max_height = heights[stk.top()];
            stk.pop();
            max_area = max(max_area, int(last_max_height * (heights.size() - stk.top() - 1)) );
        }
        return max_area;
    }
};




int main()
{

    vector<int> test{2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << sol.largestRectangleArea(test) << endl;
}