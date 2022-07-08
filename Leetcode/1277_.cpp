#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // dp[i][j]代表  1. 以目前這個小方塊為bottom right的最大square的size
                    //  2. 目前以這個小方塊為bottom right總共有多少個小squares.  
        int result = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {

                // 從第二行開始就要開始找, 如果小square是1的話, 找出左邊, 上方, 左上角最小的square, 再加上本身這個square就就是目前的dp[i][j]
                // dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
                if(matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                }
                result += matrix[i][j];    
            }
        }
        return result;
        
    }
};


int main()
{
    vector<vector<int>> test{{0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
    Solution sol;
    std::cout << sol.countSquares(test) << std::endl;
}



