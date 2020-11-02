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
        vector< vector<int> > move{ {0,1}, {1,0}, {0,-1}, {-1,0}};
        for(const auto＆ e: instructions)
        {
            if( e == 'R') direction = (direction + 1) % 4;
            else if ( e == 'L' ) direction = (direction + 3) % 4;
            else{
                x = move[direction][0];
                y = move[direction][1];
            }
        }
        return ((x == 0 && y == 0) || direction != 0);
        
    }
};

int main()
{
    string test = "GGLLGG";
    Solution sol;
    cout << sol.isRobotBounded(test) << endl;

}