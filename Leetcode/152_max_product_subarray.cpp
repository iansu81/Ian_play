#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 每次遍歷元素的時候, 都記錄下到這個元素的時候的最大跟最小, 每次比較新元素都比較自己, 之前最小*自己, 之前最大*自己




class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int prev_min = nums[0];
        int prev_max = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int current_min = min(min(nums[i], nums[i]*prev_min), nums[i]*prev_max);
            int current_max = max(max(nums[i], nums[i]*prev_min), nums[i]*prev_max);
            ans = max(ans, current_max);
            prev_min = current_min;
            prev_max = current_max;
            
        }
        return ans;
    }
};

int main()
{
    vector<int> test{-2,3,-4};
    Solution sol;
    cout << "Ans: " << sol.maxProduct(test) << endl;


}