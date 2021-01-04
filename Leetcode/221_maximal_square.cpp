#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 假設題目矩陣是：1 1
//              1 1
// 這題的state transition function 就是如果遍歷到'1'的時候, 
// dp[i][j] = mins(dp[i-1][j-1], dp[i-1][j], dp[i][j-]) + 1;
// 如果是'1'的話, 確認左上, 右上, 跟左邊的值然後＋1;
// 一開始必須要先建立一個dp[3][3]的矩陣, 把matrix size加一的原因是我們要遍歷第一行跟第一列,
// 如果不加一, 就必須要加一些special if condition去處理第一行跟第一列, 否則i-1, j-1無法處理
// 這邊dp[i][j]代表的意義就是在原本矩陣(i-1, j-1)的位置, 最大正方形邊長
// 每次遍歷完, 確認有沒有比maximum number更大

// pokaa3a解法
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int maxSquare = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxSquare = max(maxSquare, dp[i][j] * dp[i][j]);
                }
            }
        }
        return maxSquare;
    }
};




// Optimized space:
// 因為其實我們只要比較左上, 上方, 左邊的值, 所以其實只要一個一維的矩陣,
// 一個值去紀錄左上方的值, 還有一個紀錄最大值就好

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col;
        if( row > 0 ){
            col = matrix[0].size();
        }
        else{
            col = 0;
        }
        
        int pre = 0;
        vector<int> dp(col+1, 0) ;
        int maxsq = 0;
        for( int i = 1 ; i <= row ; i++ ){
            for( int j = 1 ; j <= col ; j++ ){
                int temp = dp[j];
                if( matrix[ i - 1 ][ j - 1] == '1'){
                    dp[ j ] = min( min( dp[j-1] , pre ) , dp[j] ) + 1;
                    maxsq = max( maxsq , dp[j]);
                }
                //這個else極為重要
                else{
                    dp[j] = 0;
                }
                pre = temp;
            }
        }
        return maxsq*maxsq;
        
    }
};