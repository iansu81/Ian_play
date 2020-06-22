#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector< vector<Interval> > schedule) {

        // 把所有人不行的時間都弄成一個vector
        vector<Interval> all;
        for(int i = 0; i < schedule.size(); i++)
        {
            for(int j = 0 ; j < schedule[i].size(); j++)
            {
                all.push_back(schedule[i][j]);
            }
        }
        //把這些人的時間根據start排序
        sort(all.begin(), all.end(), [](const Interval &left, const Interval &right) -> bool
        {
            return left.start < right.start;
        }
        );

        // 利用latest_end_time去紀錄前面最晚不行的時間,如果下一個元素的開始大於這個時間,代表中間有空閑可以開會
        int latest_end_time = -1;
        vector<Interval> ans;
        for(const auto &element: all )
        {
            if( latest_end_time < element.start && latest_end_time != -1)
            {
                ans.push_back(Interval(latest_end_time, element.start));

            }
            latest_end_time = max(latest_end_time, element.end);
        }

        return ans;

    }
};

int main()
{
    vector< vector<Interval> > schedule;
    vector<Interval> p1;
    Interval p1_1(1,2);
    p1.push_back(p1_1);
    Interval p1_2(5,6);
    p1.push_back(p1_2);
    schedule.push_back(p1);


    vector<Interval> p2;
    Interval p2_1(1,3);
    p2.push_back(p2_1);
    Interval p2_2(4,10);
    p2.push_back(p2_2);
    schedule.push_back(p2);







}