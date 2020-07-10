#include <vector>
#include <queue>


using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int fresh = 0;
        int days = 0;
        queue<pair<int, int>> rotten_list;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) rotten_list.push(make_pair(i,j));
            }
        }
        while(rotten_list.empty())
    }
};

int main(){


}