#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>


using namespace std;



class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int result = 0;
        
        // 依照結束的時間排序, 我們希望minimize 移除的interval, 所以要保留最多的interval, 每一個interval時間越短越好
        std::sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b){ return a[1] < b[1];});
        // 紀錄第一個interval的結束時間
        int latest_end = intervals[0][1];

        // 當下一個interval的開始時間比前面那一個結束時間晚的時候, 就必須要移除, 如果比結束時間晚, 就不需要移除, 
        // 但此時就要把用來追蹤最晚結束時間的variable update
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < latest_end) result++;
            else latest_end = intervals[i][1]; 
        }

        return result;
        
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


