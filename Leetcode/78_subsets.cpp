



#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        backtrack(0, nums, tmp, result);
        return result;
        
    }

    void backtrack(int start, vector<int>& nums, vector<int>& record, vector<vector<int>>& result){
        result.push_back(record);

        for(int i = start; i < nums.size(); i++) {
            record.push_back(nums[i]);
            backtrack(i+1, nums, record, result);
            record.pop_back();
        }

    }

};


int main()
{
    vector<int> test{1, 2, 3};
    Solution sol;
    vector<vector<int>> output = sol.subsets(test);
    for(const auto& v: output) {
        std::cout << "[";
        for(const auto& i: v) {
            cout << i <<',';
        }
        std::cout << "]";
        std::cout << endl;
    }
    
}