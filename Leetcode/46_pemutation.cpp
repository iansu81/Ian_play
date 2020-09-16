#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> record;
        helper(nums, result, 0);
        return result;

    }
    // Start 其實就是固定前start個位置, 然後開始換後面的數字, key point: 換完之後要讓他 recover 成原本的樣子, 好坐下一次置換
    // ex: [1,2,3] swap(nums[0],nums[0]) ＝> 固定1 => [1,2,3], [1,3,2]
    void helper( vector<int> nums, vector<vector<int>>& result, int start)
    {
        if(start >= nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            helper(nums, result, start+1);
            swap(nums[i], nums[start]);
        }
    }

};


int main()
{
    vector<int> test_case{1,2,3};
    Solution sol;
    vector<vector<int>> result = sol.permute(test_case);
    for(int i = 0 ; i < result.size(); i++)
    {
        for(int j = 0 ; j < result[i].size(); j++)
        {
            cout << result[i][j] << ',';
        }
        cout << endl;
    }



}

// Input : [ 1, 2, 3 ] Output : [
//     [ 1, 2, 3 ],
//     [ 1, 3, 2 ],
//     [ 2, 1, 3 ],
//     [ 2, 3, 1 ],
//     [ 3, 1, 2 ],
//     [ 3, 2, 1 ]
// ]