#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;


// 可以參考 https://leetcode.com/problems/task-scheduler/solution/ solution2的圖
// 總共有兩種情況：
1. 最高頻率的task 先排,剩下的元素已經把idle time 佔滿了, 這時候答案就是len(task)
2. 如果idle time還沒被填滿, 假設最高頻率的A出現fmax次, idle必須要n個slot, 中間的A+idle slot總共有fmax-1個,每一個是(n個idle time加上A)
所以總共有(fmax-1)*(n+1) , 然後這時候還剩下一個A(如果有其他跟A一樣頻率的元素就是A+....), 所以答案就是(fmax-1)*(n+1)+最高頻率元素的數量
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_freq_table(26,0);
        for(const auto &e: tasks)
        {
            task_freq_table[e-'A']++;
        }
        int max_freq = -1;
        int num_max = 0;
        for(const auto &e: task_freq_table)
        {   
            if(e > max_freq)
            {
                max_freq = e;
                num_max = 1;
            }
            else if( e == max_freq)
            {
                num_max++;
            }
        }

        return max(int(tasks.size()), (max_freq - 1)*( n + 1 )+num_max );
    }
};


int main()
{

    Solution sol;
    vector<char> test{'A','A','A','A','A','A','B','C','D','E','F','G'};
    cout << "Ans: " << sol.leastInterval(test, 2);

}