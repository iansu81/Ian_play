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
        sort(intervals.begin(), intervals.end(),[](const vector<int>& A, const vector<int>&B){
            return A[0] < B[0];
        });
        priority_queue<int, vector<int>, greater<int>> occupied_room;
        occupied_room.push(intervals[0][1]);
        for(int i = 1; i < intervals.size() ; i++)
        {
            if(intervals[i][0] >= occupied_room.top()){

                occupied_room.pop();
            }
            occupied_room.push(intervals[i][1]);
        }
        return occupied_room.size();
    }
};



int main(){
    vector<vector<int>> test{{ 0, 30 }, { 5, 10 }, { 15, 20 }};
    Solution sol;
    cout << sol.minMeetingRooms(test) << endl;
}