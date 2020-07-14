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
                if(grid[i][j] == 2) rotten_list.push_back(make_pair(i,j));
            }
        }
        while( !rotten_list.empty() && fresh ) 
        { 
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
                    rotten_list.push_back(center.first - 1, center.second);
                }
                // Check right
                if ((center.second + 1) < grid[0].size() && grid[center.first][center.second+1] == 1)
                {
                    resh--;
                    grid[center.first][center.second+1] = 2; 
                    rotten_list.push_back(center.first, center.second+1);
                }

                // Check left
                if ((center.second - 1) >= 0 && grid[center.first][center.second - 1] == 1)
                {
                    resh--;
                    grid[center.first][center.second-1] = 2; 
                    rotten_list.push_back(center.first, center.second-1);
                }

                //Check down
                if ((center.first + 1) < grid.size() && grid[center.first+1][center.second] == 1)
                {
                    resh--;
                    grid[center.first+1][center.second] = 2; 
                    rotten_list.push_back(center.first+1,center.second);
                }
            }
            days++;


        }
        return fresh ? -1: days;
    }
};

int main(){

    vector<int> test1{2,1,1};
    vector<int> test2{1,1,0};
    vector<int> test3{0,1,1};
    vector<vector<int>> test = {};
    


}