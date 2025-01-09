#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>


using namespace std;



class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        int prev_end = points[0][1];
        int ans = 1;
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > prev_end) {
                ans++;
                prev_end = points[i][1];
            }
        }
        return ans;

    }
}; 


int main() {
    vector<vector<int>> test{{1,2},{2,3},{3,4},{1,3}};

    vector<vector<int>> test2{{1,2},{1,2},{1,2}};
    Solution sol;
    int ans = sol.eraseOverlapIntervals(test);
    int ans2 = sol.eraseOverlapIntervals(test2);
    std::cout << "Result: " << ans2 ;
    std::cout << endl;
}