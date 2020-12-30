#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // record the element which has been visited
        // key: current visting value, val: index
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(record.count(target - nums[i]))
            {
                ans.push_back(record[target-nums[i]]);
                ans.push_back(i);
            }
            else
            {
                record[nums[i]] = i;
            }
        }
        return ans;
    }
};