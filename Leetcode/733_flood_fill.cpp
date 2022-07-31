#include <vector>

using namespace std;

class Solution {
public:

    void DFS(vector<vector<int>>& image, int row, int col, int orig_col, int new_col) {
        if(image[row][col] == orig_col) {
            image[row][col] = new_col;

            if((col-1) >= 0) DFS(image, row, col-1, orig_col, new_col);
            if((col+1) < image[0].size()) DFS(image, row, col+1, orig_col, new_col);
            if((row-1) >= 0) DFS(image, row-1, col, orig_col, new_col);
            if((row+1) < image.size()) DFS(image, row+1, col, orig_col, new_col);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig_col = image[sr][sc];
        DFS(image, sr, sc, orig_col, color);
        return image;
    }

};