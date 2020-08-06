#include <iostream>
#include <vector>

using namespace std;


class Solution
{
    private:
        vector<vector<int>> current_intervals;
    public:
        
        void add( vector<int> &new_interval )
        {
            vector<vector<int>> temp = current_intervals;
            if (current_intervals.size() == 0)
            {
                current_intervals.push_back(new_interval);
                return;
            }

            vector<vector<int>>::iterator it = temp.begin();
            while (it != temp.end() && new_interval[0] > (*it)[0])
            {
                it++;
            }
            temp.insert(it, new_interval);

            current_intervals.clear();
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
        void remove( vector<int> &old_interval)
        {
            vector<vector<int>> ans;
            for (const auto &interval : current_intervals)
                if (interval[1] <= old_interval[0] || interval[0] >= old_interval[1])
                    ans.push_back(interval);
                else
                {
                    if (interval[0] < old_interval[0])
                        ans.push_back({interval[0], old_interval[0]});
                    if (interval[1] > old_interval[1])
                        ans.push_back({old_interval[1], interval[1]});
                }
            current_intervals = ans;
        }
};


int main(){
    vector<int> test1{1,5};
    vector<int> test2{2,3};
    vector<int> test3{6,8};
    vector<int> test4{4,7};
    vector<int> test5{2,7};
    Solution sol;
    sol.add(test1);

    sol.remove(test2);
    sol.add(test3);

    sol.remove(test4);

    sol.add(test5);
    for (int i = 0; i < sol.current_intervals.size(); i++)
    {
        for (int j = 0; j < sol.current_intervals[i].size(); j++)
        {
            cout << sol.current_intervals[i][j] << ',';
        }
        cout << endl;
    }
    // for(int i = 0; i < sol.current_intervals.size(); i++){
    //     for(int j = 0; j < sol.current_intervals[i].size(); j++){
    //         cout << sol.current_intervals[i][j] << ',';
    //     }
    //     cout << endl;
    // }
}
