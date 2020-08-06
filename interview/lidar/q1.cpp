#include <iostream>
#include <vector>

using namespace std;


class Interval
{
    private:
        vector<vector<int>> current_intervals;
    public:
        
        void add( vector<int> &new_interval )
        {
            /*  
                If the current interval list is empty, just push the new interval
                into it and return
            */
            if (current_intervals.size() == 0)
            {
                current_intervals.push_back(new_interval);
                return;
            }

            /*
                1. Copy the current interval to a temp vector
                2. All intervals are sorted, insert the new into temp based 
                on the starting time.
            */
            vector<vector<int>> temp = current_intervals;
            vector<vector<int>>::iterator it = temp.begin();
            while (it != temp.end() && new_interval[0] > (*it)[0])
            {
                it++;
            }
            temp.insert(it, new_interval);

            // Clean the curent interval
            current_intervals.clear();

            /* 
                Iterate through all the element in temp(sorted), and handle the overlapping interval here.
                If element.start > last element.end => no overlap => push it into the vector. 
                else => overlap => pick the maximum end time
            */
            for (const auto &element : temp)
            {
                if (current_intervals.empty() || current_intervals.back()[1] < element[0])
                {
                    current_intervals.push_back(element);
                }
                else
                {
                    current_intervals.back()[1] = max(current_intervals.back()[1], element[1]);
                }
            }
        }
        void remove( vector<int> &remove_interval)
        {
            vector<vector<int>> ans;
            for (const auto &interval : current_intervals)
                // Handle non-overlapping intervals
                if (interval[1] <= remove_interval[0] || interval[0] >= remove_interval[1])
                    ans.push_back(interval);
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
                    if (interval[0] < remove_interval[0])
                        ans.push_back({interval[0], remove_interval[0]});
                    if (interval[1] > remove_interval[1])
                        ans.push_back({remove_interval[1], interval[1]});
                }
            current_intervals = ans;
        }
        vector<vector<int>> get_ans()
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
    interval.add(test1);
    interval.remove(test2);
    interval.add(test3);
    interval.remove(test4);
    interval.add(test5);

    
    vector<vector<int>> resutl = interval.get_ans();
    for (int i = 0; i < resutl.size(); i++)
    {
        for (int j = 0; j < resutl[i].size(); j++)
        {
            cout << resutl[i][j] << ',';
        }
        cout << endl;
    }

}
