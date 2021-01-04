// 類似number of island, 做DFS上下左右去尋找
// 每碰到一個1就把那個點設成0然後繼續尋找下去




class Solution {

public:
    int count = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count = max(count,area(grid,i,j));
                }
            }
        }
        return count;
    };
    int area(vector<vector<int>>& grid, int r, int c){

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        return (1+ area(grid,r + 1, c) + area(grid, r - 1, c) + area(grid,r, c + 1) + area(grid,r,c - 1));
            
            
    };