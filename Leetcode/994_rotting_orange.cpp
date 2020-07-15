#include <vector>
#include <queue>
#include <iostream>


using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int fresh = 0;
        int days = 0;
        queue<pair<int, int>> rotten_list;
        //記錄所有爛掉的橘子的位置跟新鮮橘子的個數,並把爛掉的橘子丟到queue裡面去紀錄
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) rotten_list.push(make_pair(i,j));
            }
        }
        //當沒有新鮮橘子,但是queue 裡面仍然有東西, 代表全部都變壞了,所以停止
        //或者是當還有新鮮橘子,但是queue裡面沒東西, 代表有新鮮橘子是沒辦法被碰到的,所以也停止
        while( !rotten_list.empty() && fresh ) 
        { 
            //iterate 在今天內所有的爛橘子,找這些爛橘子的上下左右的好橘子,把他們也變爛橘子, 然後push到queue裡面隔一天繼續搜尋
            int size = rotten_list.size();
            while(size--)
            {
                pair<int, int> center = rotten_list.front();
                rotten_list.pop();
                // Check up
                if ((center.first - 1) >= 0 && grid[center.first-1][center.second] == 1)
                {
                    fresh--;
                    grid[center.first - 1][center.second] = 2; 
                    rotten_list.push(make_pair(center.first - 1, center.second));
                }
                // Check right
                if ((center.second + 1) < grid[0].size() && grid[center.first][center.second+1] == 1)
                {
                    fresh--;
                    grid[center.first][center.second+1] = 2; 
                    rotten_list.push(make_pair(center.first, center.second+1));
                }

                // Check left
                if ((center.second - 1) >= 0 && grid[center.first][center.second - 1] == 1)
                {
                    fresh--;
                    grid[center.first][center.second-1] = 2; 
                    rotten_list.push(make_pair(center.first, center.second-1));
                }

                //Check down
                if ((center.first + 1) < grid.size() && grid[center.first+1][center.second] == 1)
                {
                    fresh--;
                    grid[center.first+1][center.second] = 2; 
                    rotten_list.push(make_pair(center.first+1,center.second));
                }
            }
            days++;


        }
        //當fresh 橘子還有剩代表不成功, return -1, 不然就return 所需天數
        return fresh ? -1: days;
    }
};

int main(){

    vector<int> test1{2,1,1};
    vector<int> test2{1,1,0};
    vector<int> test3{0,1,1};
    vector<vector<int>> test{test1, test2, test3};
    Solution sol;
    cout << "Ans: " << sol.orangesRotting(test);
}