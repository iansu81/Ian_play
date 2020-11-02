#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int direction = 0;
        // 四種移動, 設定index = 0 的時候是向上的, index = 1 向右, index = 2 向下, index = 3 向左
        vector< vector<int> > move{ {0,1}, {1,0}, {0,-1}, {-1,0}};
        for(const auto &e: instructions)
        {
            // 往右轉90度 direction +1
            if( e == 'R') 
            {
                direction = (direction + 1) % 4;
            }
            //  往左轉90度 因為不想要有負的, 所以＋3 再 mod
            else if ( e == 'L' ) 
            {
                direction = (direction + 3) % 4;
            }
            
            else{
                x = x + move[direction][0];
                y = y + move[direction][1];
            }
        }
        // 確認最後有沒有回到原點, 或者方向不是向上, 不是向上的話在2個iteration或4個iteration之後就會繞回原本的circle,所以也符合規定
        return ((x == 0 && y == 0) || direction != 0);
        
    }
};

int main()
{
    string test = "GLRLLGLL";
    Solution sol;
    cout << sol.isRobotBounded(test) << endl;

}