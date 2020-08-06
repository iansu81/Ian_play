#include <iostream>
#include <vector>
#include <utility>

using namespace std;


class Interval
{
    private:
        vector<pair<int, int>> current_intervals;
    public:
        // constructor
        Interval()
        {
            current_intervals = {};
        }
        void add( int start, int end )
        {
            /*  
                If the current interval list is empty, just push the new interval
                into it and return
            */
            if (current_intervals.size() == 0)
            {
                current_intervals.push_back(make_pair(start, end));
                return;
            }

            /*
                1. Copy the current interval to a temp vector
                2. All intervals are sorted, insert the new into temp based 
                on the starting time.
            */
            vector<pair<int, int>>::iterator it = current_intervals.begin();
            while (it != current_intervals.end() && start > it->first)
            {
                it++;
            }
            current_intervals.insert(it, make_pair(start, end));
            vector<pair<int, int>> temp {};

            /* 
                Iterate through all the element in temp(sorted), and handle the overlapping interval here.
                If element.start > last element.end => no overlap => push it into the vector. 
                else => overlap => pick the maximum end time
            */
            for (const auto &element : current_intervals)
            {
                if (temp.empty() || temp.back().second < element.first)
                {
                    temp.push_back(element);
                }
                else
                {
                    temp.back().second = max(temp.back().second, element.second);
                }
            }
            current_intervals = temp;
        }
        void remove( int start, int end)
        {
            vector<pair<int, int>> ans;
            for (const auto &interval : current_intervals)
                // Handle non-overlapping intervals
                if (interval.second <= start || interval.first >= end)
                {
                    ans.push_back(interval);
                }
                    
                /*
                    Handle overlapping conditions
                    [3, 6] remove [4,5] => [3,4], [5,6]
                */
                else
                {
                    /*  If interval.start < remove_interval.start:
                            keep [interval.start, remove_interval.start
                        If interval.end > remove_interval.end:
                            keep [remove_interval.end, interval_end]
                    */
                    if (interval.first < start)
                        ans.push_back(make_pair(interval.first, start));
                    if (interval.second > end)
                        ans.push_back(make_pair(end, interval.second));
                }
            current_intervals = ans;
        }
        vector<pair<int,int>> get_ans()
        {
            return current_intervals;
        } 
};


int main(){
    vector<int> test1{1,5};
    vector<int> test2{2,3};
    vector<int> test3{6,8};
    vector<int> test4{4,7};
    vector<int> test5{2,7};

    Interval interval;
    interval.add(1,5);
    interval.remove(2,3);
    interval.add(6,8);
    interval.remove(4,7);
    interval.add(2,7);

    vector<pair<int, int>> result = interval.get_ans();
    for (int i = 0; i < result.size(); i++)
    {

        cout << result[i].first << ',' << result[i].second;
        cout << endl;
    }
}
