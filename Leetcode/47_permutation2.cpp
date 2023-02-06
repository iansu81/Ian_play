#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);

        // 要先sort才方便找出有沒有相同的元素
        std::sort(nums.begin(), nums.end());
        backtrack(0, nums, used, tmp, result);
        return result;
        
    }
    void backtrack(int start, vector<int>& nums, vector<bool>& used, vector<int>& record, vector<vector<int>>& result) {
        if(start == nums.size()) {
            result.push_back(record);
        }


        // 因為是排列, 所以這邊i 都從0開始, 然後利用used[i]來紀錄有沒有被用過
        for(int i = 0; i < nums.size(); i++) 
        {
            // 如果被用過就不用再遍歷了
            if(used[i]) continue;

            // 確定i>0的原因是因為後面要跟i-1做比較, 沒有的話會access到錯的memory
            // 如果前一個相同的元素還沒有被用過的話, 就不用再繼續遍歷下去, 因為不會是一個valid的解
            // ex: [1, 2, 2'], 因為這一題[1,2,2']跟[1,2',2]算是相同的解, 所以我們想要維持在遍歷的過程中, 2一定在2'之前
            // 所以如果2還沒被使用過2'就不應該被使用
            if(i > 0 && (nums[i] == nums[i-1]) && !used[i-1]) continue;

            used[i] = true;
            record.push_back(nums[i]);
            backtrack(start+1, nums, used, record, result);
            used[i] = false;
            record.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> test{1, 1, 2};
    vector<vector<int>> output = sol.permuteUnique(test);
    for(const auto& v: output) {
        std::cout << "[";
        for(const auto& i: v) {
            cout << i <<',';
        }
        std::cout << "]";
        std::cout << endl;
    }
    
}