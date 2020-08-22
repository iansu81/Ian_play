#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if(intervals.size() == 0)
        {
            return 0;
        }
        // 把開始的時間從小排到大
        sort(intervals.begin(), intervals.end(),[](const vector<int>& A, const vector<int>&B){
            return A[0] < B[0];
        });
        // 建立一個min heap, 紀錄每個meeting 結束的時間
        priority_queue<int, vector<int>, greater<int>> occupied_room;
        occupied_room.push(intervals[0][1]);
        for(int i = 1; i < intervals.size() ; i++)
        {
            // 當新的meeting 時間比min heap裡面最早結束的時間還要小的時候, 代表必須再開一間會議室, 此時就把新的meeting結束時間push 進去做紀錄
            if(intervals[i][0] >= occupied_room.top()){

                occupied_room.pop();
            }
            occupied_room.push(intervals[i][1]);
        }
        // 最後紀錄min heap的size就知道最多必須開多少間會議室
        return occupied_room.size();
    }
};



int main(){
    vector<vector<int>> test{{ 0, 30 }, { 5, 10 }, { 15, 20 }};
    Solution sol;
    cout << sol.minMeetingRooms(test) << endl;
}