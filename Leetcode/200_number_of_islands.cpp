#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if( grid.size() == 0 ){
                return 0;
            }
            int count = 0;
            for( int i = 0; i < grid.size() ; i++ ){
                for( int j = 0; j < grid[i].size() ; j++ ){
                    if( grid[i][j] == '1' ){
                        count ++;
                        dfs( grid , i , j );
                    }

                }
            }
            return count;
        }
        void dfs( vector<vector<char>>& grid , int r , int c ){

            std::cout << "r:" << r << std::endl;
            std::cout << "c:" << c << std::endl;
            grid[r][c] = '0';  
            if( ( r - 1 ) >= 0 && grid[r-1][c] == '1'){
                dfs(grid , r-1 , c );
            }
            if( ( r + 1 ) < grid.size() && grid[r+1][c] == '1' ){
                dfs(grid, r + 1, c );
            }
            if( ( c - 1)  >= 0 && grid[r][c-1] == '1'){
                dfs( grid , r , c - 1 );
            }
            if( (c + 1) < grid[1].size() && grid[r][c+1] == '1' ){
                dfs( grid , r , c + 1 );
            }
        }
    
};

int main() {

    vector<vector<char>> test{{'1'}};
    Solution sol;
    int result = sol.numIslands(test);
    std::cout << "Ans: " << result << std::endl;


}