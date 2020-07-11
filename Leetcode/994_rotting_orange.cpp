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
        while( !rotten_list.empty() && fresh ) 
        { 
            int size = rotten_list.size();
            while(size--)
            {
                pair<int, int> center = rotten_list.front();
                rotten_list.pop();
                pair<int, int> right_point (center.first, center.second+1);
                pair<int, int> up_point (center.first-1, center.second);
                pair<int, int> left_point (center.first, center)
                pair<int, int> _point =
                pair<int, int> up_point =
            }



        }
        return fresh 
    }
};

int main(){

    vector test1


}