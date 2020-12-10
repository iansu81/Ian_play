#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <unordered_map>

using namespace std;


// Note: 
// 1. 記得用一個unordered_map來紀錄尋訪過的值, 不然會超時
// 2. unordered_map的key不能用pair

class Solution {

private:
    unordered_map<string, int> record;

public:
    int dp(int x, int y){
        string xy = std::to_string(x) + "," + std::to_string(y);
        if(record.count(xy))
        {
            return record[xy];
        }
        if ( (x+y) == 0)
        {
            return 0;
        }
        if( (x+y) == 2)
        {
            return 2;
        }
        int ans = min( dp(abs(x-1), abs(y-2)) , dp(abs(x-2), abs(y-1))) + 1;
        record[xy] = ans;
        return ans;
    }
    int minKnightMoves(int x, int y) {
        return dp(abs(x), abs(y));
    }
};


int main()
{
    Solution sol;
    cout << "Ans: " << sol.minKnightMoves(5, 5) << endl;
}