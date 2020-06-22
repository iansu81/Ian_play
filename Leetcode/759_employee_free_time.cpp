#include <iostream>
#include <vector>

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

// class Solution {
// public:
//     vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
//     }
// };

int main()
{
    vector< vector<Interval> > schedule;
    vector<Interval> p1;
    vector<Interval> p2;
    Interval p1_1(1,2);
    p1.push_back(p1_1);
    Interval p1_2(5,6);
    p1.push_back(p1_2);
    Interval p2_1(1,3);
    p2.push_back(p2_1);
    Interval p2_2(4,10);
    p2.push_back(p2_2);
    schedule.push_back(p2);







}