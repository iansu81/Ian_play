#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Keynote: 
//     當找到第一個letter之後就開始對接下來的字做DFS, helper的d用來track比較到第幾個letter, x,y則是track boad裡面的index,
//     當out of range 就不用繼續找, 當letter跟下一個不一樣也不用繼續找了,找到那自之後先把board[x][y]設成'0',以免重複找,當找完再把這letter回復


class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if(board.size() == 0) return false;
        bool ans = false;
        row = board.size();
        col = board[0].size(); 
        for(int i = 0; i < row; i ++)
        {
            for(int j = 0; j < col; j++)
            {
                if (helper(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }

    // word記得用const string &, 沒有的話速度差很多
    bool helper(vector<vector<char>> &board, const string& word, int d, int x, int y)
    {   
        if( x < 0 || x >= row || y < 0 || y >= col || board[x][y] != word[d]) return false;
        if (d == word.length() - 1) return true;
        char ch = board[x][y];
        board[x][y] = '0';
        bool result = helper(board, word, d + 1, x - 1, y) ||
            helper(board, word, d + 1, x + 1, y) ||
            helper(board, word, d + 1, x, y - 1) ||
            helper(board, word, d + 1, x, y + 1);
        board[x][y] = ch;

        return result;
    }
private: 
    int row;
    int col;
};


int main()
{
    vector<vector<char>> test{
        { 'A', 'B', 'C', 'E' }, 
        { 'S', 'F', 'C', 'S' }, 
        { 'A', 'D', 'E', 'E' }
    };

    string test_str = "ABCCED";
    Solution sol;
    cout << sol.exist(test, test_str) << endl;
}