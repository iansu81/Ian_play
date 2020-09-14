#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        helper(3,nums,result);

    }
    void helper(int level, vector<int> current, vector<int> &record, vector<vector<int>> &result)
    {
        if(level == 0)
        {
            result.push_back(record);
            return;
        }
        record.push_back(current[level];
        helper(level-1, current,record, result);

    }

};


int main()
{


}

// Input : [ 1, 2, 3 ] Output : [
//     [ 1, 2, 3 ],
//     [ 1, 3, 2 ],
//     [ 2, 1, 3 ],
//     [ 2, 3, 1 ],
//     [ 3, 1, 2 ],
//     [ 3, 2, 1 ]
// ]