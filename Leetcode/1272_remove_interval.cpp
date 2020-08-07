#include <vector>
#include <iostream>


using namespace std;

class Solution
    {
    public:
        vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved)
        {
            vector<vector<int>> ans;
            for(auto& element : intervals)
            {
                // Handle non-overlapping intervals
                if (toBeRemoved[0] >= element[1] || element[0] >= toBeRemoved[1])
                {
                    ans.push_back(element);
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

                    if (element[0] < toBeRemoved[0])
                    {
                        ans.push_back({element[0], toBeRemoved[0]});
                    }
                    if(element[1] > toBeRemoved[1])
                    {
                        ans.push_back({toBeRemoved[1], element[1]});
                    }
                }
            }
            return ans;

        }
};


int main()
{

    vector<vector<int>> test1{{ 0, 2 }, { 3, 4 }, { 5, 7 }};
    vector<int> remove1{1,6};
    vector<vector<int>> test2{{0, 5}};
    vector<int> remove2{2,3};
    Solution sol;
    vector<vector<int>> result = sol.removeInterval(test1, remove1);
    for(int i = 0; i < result.size(); i ++){
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << ',';
        }
        cout << endl;
    }
}